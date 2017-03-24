class Task {
	typedef void(*callback_t)(void);
	unsigned long Last = 0;
	unsigned long Delay = 0;
	callback_t callback;

public:
	Task(unsigned long delay) {
		Delay = delay;
	}

	void setupCallbackFunc(callback_t callback_func) {
		callback = callback_func;
	}

	void setLast(unsigned long last) {
		Last = last;
	}

	bool Update() {
		unsigned long current = millis();
		if (current - Last > Delay)
			if (callback) {
				callback();
			}
	}
};


//--- USING ---
Task periodicTask(30000);

periodicTask.setupCallbackFunc(PeriodicCallback);

periodicTask.Update();

void PeriodicCallback() {
	periodicTask.setLast(millis());
}