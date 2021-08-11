#ifndef GTKMM_EXAMPLE_MAINWINDOW_H
#define GTKMM_EXAMPLE_MAINWINDOW_H

#include <gtkmm/applicationwindow.h>
#include <gtkmm/builder.h>
#include <gtkmm/box.h>
#include <gtkmm/stack.h>
#include <memory>

#define DEFAULT_WINDOW_WIDTH  400
#define DEFAULT_WINDOW_HEIGHT 400

class MainWindow : public Gtk::ApplicationWindow
{
  public:
    MainWindow();
    ~MainWindow() override;

  protected:
    //Signal handlers:
    void on_button_clicked();

    // GUI Builder to parse UI from xml file
    Glib::RefPtr<Gtk::Builder> builder;

    //Member widgets:
    std::unique_ptr<Gtk::Box>   m_container;
    std::unique_ptr<Gtk::Stack> m_stack;

  private:
    template <typename T_Widget>
    static std::unique_ptr<T_Widget> get_widget(const Glib::ustring name, const Glib::RefPtr<Gtk::Builder> &builder);
};

#endif // GTKMM_EXAMPLE_MAINWINDOW_H
