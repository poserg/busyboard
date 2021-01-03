#include "TumblerLed.h"
#include "Button.h"
#include "LedPanel.h"

#include "PoliceCar.h"
#include "PoliceCar2.h"
#include "EmergencyTruck.h"

// управляющие пины матрицы
#define CLK   11
#define OE    9
#define LAT   10
#define A     A0
#define B     A1
#define C     A2
#define D     A3

// объявляем объект для работы с матрицей 64х32
// включаем двойную буферизацию
RGBmatrixPanel* matrix = new RGBmatrixPanel(A, B, C, D, CLK, LAT, OE, true, 64);

#define LEFT_BUTTON_PIN 39
#define RIGHT_BUTTON_PIN 38
#define UP_BUTTON_PIN 40
#define DOWN_BUTTON_PIN 41

#define YELLOW_BUTTON_PIN 37
#define GREEN_BUTTON_PIN 35
#define BLUE_BUTTON_PIN 34
#define RED_BUTTON_PIN 36

#define YELLOW_LED_PIN 33
#define GREEN_LED_PIN 32
#define BLUE_LED_PIN 31
#define RED_LED_PIN 30

#define BIG_GREEN_LED 44
#define BIG_BLUE_LED 42

auto yellowTumbler = new TumblerLed(YELLOW_LED_PIN, YELLOW_BUTTON_PIN);
auto greenTumbler = new TumblerLed(GREEN_LED_PIN, GREEN_BUTTON_PIN);
auto blueTumbler = new TumblerLed(BLUE_LED_PIN, BLUE_BUTTON_PIN);
auto redTumbler = new TumblerLed(RED_LED_PIN, RED_BUTTON_PIN);

const int tumblerLedCount = 4;
Led* tumblerLeds[tumblerLedCount] = { yellowTumbler, greenTumbler, blueTumbler, redTumbler };
auto tumblerLedPanel = new LedPanel(tumblerLeds, tumblerLedCount);

const int buttonLedCount = 2;
Led* buttonLeds[buttonLedCount] = { new Led(BIG_GREEN_LED), new Led(BIG_BLUE_LED) };
auto buttonLedPanel = new LedPanel(buttonLeds, buttonLedCount);

const int carsCount = 3;
int currentCarIndex = 0;
Car* cars[carsCount] = { new PoliceCar(matrix), new PoliceCar2(matrix), new EmergencyTruck(matrix) };

auto upButton = new Button(UP_BUTTON_PIN);
auto leftButton = new Button(LEFT_BUTTON_PIN);
auto rightButton = new Button(RIGHT_BUTTON_PIN);

void setup() {
	matrix->begin();
	// Serial.begin(115200);

	for (int i = 0; i < tumblerLedCount; i++) {
		tumblerLeds[i]->off();
	}
	for (int i = 0; i < buttonLedCount; i++) {
		buttonLeds[i]->off();
	}
}

void showNextCar() {
	currentCarIndex++;
	if (currentCarIndex >= carsCount) {
		currentCarIndex = 0;
	}
}

void showPreviousCar() {
	currentCarIndex--;
	if (currentCarIndex <= 0) {
		currentCarIndex = carsCount - 1;
	}
}

void loop() {
	cars[currentCarIndex]->setIsFlasherOn(redTumbler->isPressed() || upButton->isPressed());
	tumblerLedPanel->processNextIteration();
	buttonLedPanel->processNextIteration();
	cars[currentCarIndex]->processNextIteration();
	if (leftButton->isPressed()) {
		showPreviousCar();
	}
	if (rightButton->isPressed()) {
		showNextCar();
	}
}
