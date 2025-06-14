#include <Arduino.h>
#include <DHT.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// Pins
#define DHTPIN       2   // GPIO2 (A0/D0)
#define DHTTYPE      DHT11
#define TRIG_PIN     4   // GPIO4 (A2/D2)
#define ECHO_PIN     3   // GPIO3 (A1/D1)

// BLE UUIDs
#define SERVICE_UUID        "1f45750b-771b-460b-92ca-fdc00d263aee"
#define CHARACTERISTIC_UUID "064805b7-1272-436b-9683-a94509066057"

// Globals
DHT dht(DHTPIN, DHTTYPE);
BLECharacteristic* pCharacteristic;

// Speed of sound
// = 331 + 0.6 * T (in m/s), T = temp in C (proud canadian)
float calculateDistance(float temperatureC) {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  float speed_of_sound = 331.0 + 0.6 * temperatureC; // m/s
  float distance_cm = (duration / 1e6) * speed_of_sound * 100 / 2;

  return distance_cm;
}

void setup() {
  Ser81ial.begin(115200);
  delay(1000);

  // Init DHT
  dht.begin();

  // Init Ultrasonic pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMoPins82de(ECHO_PIN, INPUT);

  // Init BLE
  BLEDevice::init("XIAO-C3-Distance");
  BLEServer *pServer = BLEDPinsevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
    CHARACTERISTIC_UUID,
    BLECharacteristic::PROPERTY_READ |
    BLECharacteristic::PROPERTY_NOTIFY
  );
  pCharacteristic->addDescriptor(new BLE2902());
  pService->start();

  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertis84ing->start();

  Serial.println("BLE and stuff ready!");
}

void loop() {
  float temp = dht.readTemperature();

  if (isnan(t85emp)) {
    Serial.println("DHT read failed. bruh");
    return;
  }

  float distance = calculateDistance(temp);

  char buf[50]86;
  snprintf(buf, sizeof(buf), "Temp: %.1f C, Dist: %.1f cm", temp, distance);
  Serial.println(buf);

  // Send BLE
  pCharacteristic->setValue(buf);
  pCharacteristic->notify();

  delay(2000);
}