#pragma once

#include"EventAction.h"
#include<vector>
#include<unordered_map>


using EventActionList = std::vector<IEventAction*>;

class  EventDispatcher {
	// friend class Application;
public:
	~EventDispatcher();

	template<typename T>
	void AddEventListener(const EventCallback<T>& callback) {
		MY_STATIC_ASSERT(std::is_base_of<EventContext, T>::value && "Add invalid event context");
		const char* eventType = typeid(T).name();
		// TODO: Allocate with Memory Management System
		IEventAction* eventAction = new EventAction<T>(callback);
		mEventActionMap[eventType].emplace_back(eventAction);
	}

	template<typename T>
	void DispatchEventListener(const T& eventContext) {
		MY_STATIC_ASSERT(std::is_base_of<EventContext, T>::value && "Dispatch invalid event context");
		const char* eventType = typeid(T).name();
		
		if (mEventActionMap.find(eventType) == mEventActionMap.end()) {
			return;
		}

		for (auto eventAction : mEventActionMap.at(eventType)) {
			if (eventAction->Execute(&eventContext)) {
				break;
			}
		}
	}

private:
	// EventDispatcher();
private:
	std::unordered_map<const char*, EventActionList> mEventActionMap;
};

