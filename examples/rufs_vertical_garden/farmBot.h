struct DEBOUNCE {
	int pin;					// number of input pin
	int pinState;      			// the debounced value of input pin
	int pinOldState;				// previous stable state of input pin
	int pinStable;				// HIGH if pinState is stable
	long lastDebounceTime;		// last Reading time
};

typedef DEBOUNCE DEBOUNCE_DEF;
