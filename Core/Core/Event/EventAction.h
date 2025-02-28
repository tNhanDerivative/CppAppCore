#pragma once

#include"pch.h"
#include"EventContext.h"


template<typename T> using EventCallback = std::function<bool(const T&)>;

class  IEventAction {
public:
	virtual ~IEventAction() = default;
	virtual bool Execute(const EventContext*) = 0;
};

template<typename T>
class EventAction : public IEventAction {
public:
	EventAction(const EventCallback<T>& callback) : mCallback(callback) {}
	virtual bool Execute(const EventContext* eventContext) override {
		MY_STATIC_ASSERT(std::is_base_of<EventContext, T>::value && "Invalid event context");
		return mCallback(*(T*)eventContext);
	}
private:
	EventCallback<T> mCallback;
};
