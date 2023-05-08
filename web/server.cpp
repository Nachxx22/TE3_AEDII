#include <Wt/WApplication.h>
#include <Wt/Http/Request.h>
#include <Wt/Http/Response.h>
#include <Wt/Http/Client.h>
#include <Wt/WLineEdit.h>
#include <Wt/WBreak.h>
#include <Wt/WPushButton.h>

class MyApplication : public Wt::WApplication
{
public:
    MyApplication(const Wt::WEnvironment& env);

private:
    Wt::WLineEdit *num1_;
    Wt::WLineEdit *num2_;
    Wt::WPushButton *button_;
    
    void handleRequest(const Wt::Http::Request& request, Wt::Http::Response& response);
};

MyApplication::MyApplication(const Wt::WEnvironment& env)
    : Wt::WApplication(env)
{
    setTitle("Ejemplo de formulario con dos números");

    num1_ = new Wt::WLineEdit(root());
    root()->addWidget(new Wt::WBreak());
    
    num2_ = new Wt::WLineEdit(root());
    root()->addWidget(new Wt::WBreak());
    
    button_ = new Wt::WPushButton("Enviar números", root());
    button_->clicked().connect(this, &MyApplication::handleRequest);
}

void MyApplication::handleRequest(const Wt::Http::Request& request, Wt::Http::Response& response)
{
    int num1 = std::stoi(num1_->text().toUTF8());
    int num2 = std::stoi(num2_->text().toUTF8());
    int resultado = num1 + num2;
    
    response.setMimeType("text/html");
    response.out() << "<html><body>Su resultado es: " << resultado << "</body></html>";
}

int main(int argc, char **argv)
{
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
        return new MyApplication(env);
    });
}
