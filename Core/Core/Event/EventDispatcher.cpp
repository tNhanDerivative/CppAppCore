#include"EventDispatcher.h"


EventDispatcher::EventDispatcher() : mEventActionMap() {
}

EventDispatcher::~EventDispatcher() {
	for (auto& pair : mEventActionMap) {
		for (auto eventAction : pair.second) {
			MY_FREE_MEMORY(eventAction);
		}
		pair.second.clear();
	}
	mEventActionMap.clear();
}
