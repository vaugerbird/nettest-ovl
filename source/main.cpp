#define TESLA_INIT_IMPL // If you have more than one file using the tesla header, only define this in the main one
#include <tesla.hpp>    // The Tesla Header

#include <stdio.h>


class nettestGui : public tsl::Gui {


public:
    nettestGui() { }

    // Called when this Gui gets loaded to create the UI
    // Allocate all elements on the heap. libtesla will make sure to clean them up when not needed anymore
    virtual tsl::elm::Element* createUI() override {
        // A OverlayFrame is the base element every overlay consists of. This will draw the default Title and Subtitle.
        // If you need more information in the header or want to change it's look, use a HeaderOverlayFrame.
        auto frame = new tsl::elm::OverlayFrame("nettest-ovl", "by vaugerbird - test v0.0.1");

        auto list = new tsl::elm::List();// A list that can contain sub elements and handles scrolling

      //auto* startTestItem = new tsl::elm::ListItem("Start Test");
        //startTestItem->setClickListener(testBegin);
        //list->addItem(startTestItem);

        list->addItem(new tsl::elm::ListItem("Start Test"));//Select server button

        //list->addItem(new tsl::elm::ListItem("Custom Server"));//Custom server button

        frame->setContent(list);// Add the list to the frame for it to be drawn

        // Return the frame to have it become the top level element of this Gui
        return frame;
    }

    // Called once every frame to update values
    virtual void update() override {

    }

    // Called once every frame to handle inputs not handled by other UI elements
  // virtual bool handleInput(u64 keysDown, u64 keysHeld, touchPosition touchInput, JoystickPosition leftJoyStick, JoystickPosition rightJoyStick) override {
  //      return false;   // Return true here to singal the inputs have been consumed
  //  }
};

class NetOverlay : public tsl::Overlay {
public:
                                             // libtesla already initialized fs, hid, pl, pmdmnt, hid:sys and set:sys
    virtual void initServices() override {}  // Called at the start to initialize all services necessary for this Overlay
    virtual void exitServices() override {}  // Callet at the end to clean up all services previously initialized

    virtual void onShow() override {}    // Called before overlay wants to change from invisible to visible state
    virtual void onHide() override {}    // Called before overlay wants to change from visible to invisible state

    virtual std::unique_ptr<tsl::Gui> loadInitialGui() override {
        return initially<nettestGui>();  // Initial Gui to load. It's possible to pass arguments to it's constructor like this
    }
};

int main(int argc, char **argv) {
    return tsl::loop<NetOverlay>(argc, argv);
}
