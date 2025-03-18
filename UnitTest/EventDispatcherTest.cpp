#include <gtest/gtest.h>
#include "Core/Event/EventDispatcher.h"
#include "Core/Event/EventContext.h"

class EventDispatcherTest : public ::testing::Test {
public:
    EventDispatcher dispatcher;
};

// Test adding and dispatching a WindowResizedEvent
TEST_F(EventDispatcherTest, WindowResizedEventTest) {
    bool eventHandled = false;
    
    dispatcher.AddEventListener<WindowResizedEvent>([&](const WindowResizedEvent& event) {
        EXPECT_EQ(event.GetWidth(), 800);
        EXPECT_EQ(event.GetHeight(), 600);
        eventHandled = true;
        return true;
    });

    WindowResizedEvent resizeEvent(800, 600);
    dispatcher.DispatchEventListener(resizeEvent);

    EXPECT_TRUE(eventHandled);
}

// Test multiple event listeners, one of which stops propagation
TEST_F(EventDispatcherTest, MultipleEventListenersTest) {
    int listenerCount = 0;
    
    dispatcher.AddEventListener<KeyPressedEvent>([&](const KeyPressedEvent& event) {
        EXPECT_EQ(event.GetKeyCode(), 65);  // 'A' key
        listenerCount++;
        return false;  // continue to next listener
    });

    dispatcher.AddEventListener<KeyPressedEvent>([&](const KeyPressedEvent& event) {
        EXPECT_EQ(event.GetKeyCode(), 65);  // 'A' key
        listenerCount++;
        return true;  // stop propagation
    });

    // Create and dispatch event
    KeyPressedEvent keyEvent(65);
    dispatcher.DispatchEventListener(keyEvent);

    EXPECT_EQ(listenerCount, 2);
}

// Test mouse move event
TEST_F(EventDispatcherTest, MouseMovedEventTest) {
    bool eventHandled = false;
    
    dispatcher.AddEventListener<MouseMovedEvent>([&](const MouseMovedEvent& event) {
        EXPECT_DOUBLE_EQ(event.GetPositionX(), 100.5);
        EXPECT_DOUBLE_EQ(event.GetPositionY(), 200.5);
        EXPECT_DOUBLE_EQ(event.GetOffsetX(), 10.2);
        EXPECT_DOUBLE_EQ(event.GetOffsetY(), 20.3);
        eventHandled = true;
        return true;
    });

    MouseMovedEvent moveEvent(100.5, 200.5, 10.2, 20.3);
    dispatcher.DispatchEventListener(moveEvent);

    EXPECT_TRUE(eventHandled);
}

// Test event with no listeners
TEST_F(EventDispatcherTest, NoListenersTest) {
    // This should not crash
    MouseScrolledEvent scrollEvent(5.0, 10.0);
    dispatcher.DispatchEventListener(scrollEvent);
}

// Compile-time type checking test
TEST_F(EventDispatcherTest, TypeSafetyTest) {
    // This should fail to compile if uncommented
    // dispatcher.AddEventListener<std::string>([](const std::string& str) { return true; });
    
    // This should compile fine
    dispatcher.AddEventListener<KeyPressedEvent>([](const KeyPressedEvent& event) { return true; });
}


