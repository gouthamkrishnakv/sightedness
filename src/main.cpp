#include <iostream>
#include <memory>
#include <gtk-4.0/gtk/gtk.h>
#include <libadwaita-1/adwaita.h>
#include <vector>

class MainApplication {
public:
    AdwApplication *parent_inst;
    std::vector<AdwWindow> windows;

    MainApplication() {
        this->parent_inst = adw_application_new(
            "com.crosine.sightedness",
            G_APPLICATION_DEFAULT_FLAGS
        );
        g_signal_connect(
            G_OBJECT(this->parent_inst),
            "activate",
            G_CALLBACK(activate),
            this
        );
    }

    static void activate(GtkApplication *app, void *selfptr) {
        std::cout << "Activated" << std::endl;
    }

    int run(int argc, char **argv) {
        return g_application_run(G_APPLICATION(this->parent_inst), argc, argv);
    }

    ~MainApplication() {
        g_object_unref(G_OBJECT(this->parent_inst));
    }
};

auto main(int argc, char **argv) -> int {
    std::unique_ptr<MainApplication> app = std::make_unique<MainApplication>();

    int status = app->run(argc, argv);

    return status;
}

