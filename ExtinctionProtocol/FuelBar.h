#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

namespace ExtinctionProtocol {
    public ref class FuelBar : public Panel {
    private:
        int currentFuel;
        int maxFuel;
        List<int>^ fuelLog;

        // Updates color & width of fuel bar
    public:
        void UpdateAppearance() {
            double percentage = (maxFuel > 0) ? (static_cast<double>(currentFuel) / maxFuel) * 100.0 : 0.0;

            if (percentage == 0.0) {
                this->BackColor = Color::Black;  // Empty fuel
            }
            else if (percentage >= 80.0) {
                this->BackColor = Color::Green;  // High fuel
            }
            else if (percentage >= 50.0) {
                this->BackColor = Color::Orange;  // Medium fuel
            }
            else {
                this->BackColor = Color::Red;  // Low fuel
            }

            // Adjust width dynamically
            this->Width = static_cast<int>(208 * (percentage / 100.0));
            this->Invalidate();
            this->Update();
        }
    protected:
        virtual void OnPaint(PaintEventArgs^ e) override {
            Panel::OnPaint(e);
            Graphics^ g = e->Graphics;

            // Draw filled fuel portion
            int filledWidth = static_cast<int>(this->Width * (static_cast<double>(currentFuel) / maxFuel));
            g->FillRectangle(gcnew SolidBrush(this->BackColor), 0, 0, filledWidth, this->Height);
        }

    public:
        // Constructor
        FuelBar() : currentFuel(0), maxFuel(8) {
            this->Size = Drawing::Size(208, 15);
            this->Anchor = AnchorStyles::Top | AnchorStyles::Right;
            this->Location = Point(661, 49);

            fuelLog = gcnew List<int>();
            UpdateAppearance();
        }
        ~FuelBar(){
            fuelLog->Clear();
        }

        // Property for fuel level
        property int CurrentFuel {
            int get() { return currentFuel; }
            void set(int value) {
                currentFuel = Math::Max(0, Math::Min(value, maxFuel));
                fuelLog->Add(currentFuel);
                UpdateAppearance();
            }
        }
        // Property for MaxFuel
        property int MaxFuel {
            int get() { return maxFuel; }
            void set(int value) {
                if (value > 0) {
                    maxFuel = value;
                    if (currentFuel > maxFuel)
                        currentFuel = maxFuel;  // Ensure fuel doesn't exceed max limit
                    UpdateAppearance();
                }
            }
        }

        // Overload ++ (increase by 12.5%)
        FuelBar^ operator++() {
            this->CurrentFuel += 1;
            this->UpdateAppearance();
            return this;
        }

        // Overload -- (decrease by 12.5%)
        FuelBar^ operator--() {
            if (CurrentFuel > 0) {  // Prevent negative values
                CurrentFuel -= 1;
            }
            this->UpdateAppearance();
            return this;
        }

        // Reset fuel bar to 0%
        void ResetFuel() {
            this->CurrentFuel = 0;
        }
    };
}
