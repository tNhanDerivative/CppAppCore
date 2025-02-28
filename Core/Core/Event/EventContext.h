#pragma once
#include"pch.h"


class EventContext {
public:
	virtual ~EventContext() = default;
};

class WindowResizedEvent : public EventContext {
public:
	WindowResizedEvent(int32_t width, int32_t height) : mWidth(width), mHeight(height) {}
	MY_FORCE_INLINE int32_t GetWidth() const { return mWidth; }
	MY_FORCE_INLINE int32_t GetHeight() const { return mHeight; }
private:
	int32_t mWidth, mHeight;
};

class KeyPressedEvent : public EventContext {
public:
	KeyPressedEvent(int32_t keyCode) : mKeyCode(keyCode) {}
	MY_FORCE_INLINE int32_t GetKeyCode() const { return mKeyCode; }
private:
	int32_t mKeyCode;
};

class KeyHeldEvent : public EventContext {
public:
	KeyHeldEvent(int32_t keyCode) : mKeyCode(keyCode) {}
	MY_FORCE_INLINE int32_t GetKeyCode() const { return mKeyCode; }
private:
	int32_t mKeyCode;
};

class KeyReleasedEvent : public EventContext {
public:
	KeyReleasedEvent(int32_t keyCode) : mKeyCode(keyCode) {}
	MY_FORCE_INLINE int32_t GetKeyCode() const { return mKeyCode; }
private:
	int32_t mKeyCode;
};

class MouseMovedEvent : public EventContext {
public:
	MouseMovedEvent(double x, double y, double offsetX, double offsetY) : 
		xPosition(x), yPosition(y),
		xOffset(offsetX), yOffset(offsetY) {}
	MY_FORCE_INLINE double GetPositionX() const { return xPosition; }
	MY_FORCE_INLINE double GetPositionY() const { return yPosition; }
	MY_FORCE_INLINE double GetOffsetX() const { return xOffset; }
	MY_FORCE_INLINE double GetOffsetY() const { return yOffset; }
private:
	double xPosition, yPosition;
	double xOffset, yOffset;
};

class  MouseScrolledEvent : public EventContext {
public:
	MouseScrolledEvent(double offsetX, double offsetY) : xOffset(offsetX), yOffset(offsetY) {}
	MY_FORCE_INLINE double GetScrollX() const { return xOffset; }
	MY_FORCE_INLINE double GetScrollY() const { return yOffset; }
private:
	double xOffset, yOffset;
};

class MouseButtonPressedEvent : public EventContext {
public:
	MouseButtonPressedEvent(int32_t button) : mButton(button) {}
	MY_FORCE_INLINE int32_t GetButton() const { return mButton; }
private:
	int32_t mButton;
};

class MouseButtonHeldEvent : public EventContext {
public:
	MouseButtonHeldEvent(int32_t button) : mButton(button) {}
	MY_FORCE_INLINE int32_t GetButton() const { return mButton; }
private:
	int32_t mButton;
};

class MouseButtonReleasedEvent : public EventContext {
public:
	MouseButtonReleasedEvent(int32_t button) : mButton(button) {}
	MY_FORCE_INLINE int32_t GetButton() const { return mButton; }
private:
	int32_t mButton;
};
