#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

class CalculatorApp : public Wt::WApplication
{
public:
    CalculatorApp(const Wt::WEnvironment& env);

private:
    Wt::WLineEdit* firstNumberEdit_;
    Wt::WLineEdit* secondNumberEdit_;
    Wt::WText* resultText_;

    void calculate();
};

CalculatorApp::CalculatorApp(const Wt::WEnvironment& env)
    : Wt::WApplication(env)
{
    // Set up the UI
    auto container = root()->addWidget(std::make_unique<Wt::WContainerWidget>());

    auto firstNumberLabel = container->addWidget(std::make_unique<Wt::WText>("First number: "));
    firstNumberEdit_ = container->addWidget(std::make_unique<Wt::WLineEdit>());

    auto secondNumberLabel = container->addWidget(std::make_unique<Wt::WText>("Second number: "));
    secondNumberEdit_ = container->addWidget(std::make_unique<Wt::WLineEdit>());

    auto calculateButton = container->addWidget(std::make_unique<Wt::WPushButton>("Calculate"));
    calculateButton->clicked().connect(this, &CalculatorApp::calculate);

    resultText_ = container->addWidget(std::make_unique<Wt::WText>());

    setTitle("Calculator");
}

void CalculatorApp::calculate()
{
    // Get the numbers from the UI
    double firstNumber = std::stod(firstNumberEdit_->text().toUTF8());
    double secondNumber = std::stod(secondNumberEdit_->text().toUTF8());

    // Calculate the result
    double result = firstNumber + secondNumber;

    // Update the UI with the result
    resultText_->setText("Result: " + std::to_string(result));
}

int main(int argc, char** argv)
{
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
        return std::make_unique<CalculatorApp>(env);
    });
}
