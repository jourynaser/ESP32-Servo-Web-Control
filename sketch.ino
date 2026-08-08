#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

const char* ssid = "ESP32-Servo-Control";
const char* password = "12345678";

const int SERVO_PIN = 13;
const int GREEN_LED = 26;
const int RED_LED = 27;

Servo myServo;
WebServer server(80);

String webpage() {
  return R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Servo Control</title>

  <style>
    body {
      font-family: Arial;
      text-align: center;
      background-color: #f5f5f5;
      padding-top: 80px;
    }

    .box {
      background-color: white;
      width: 320px;
      margin: auto;
      padding: 30px;
      border-radius: 15px;
    }

    button {
      width: 120px;
      padding: 15px;
      margin: 10px;
      border: none;
      border-radius: 10px;
      color: white;
      font-size: 18px;
      cursor: pointer;
    }

    .open {
      background-color: green;
    }

    .close {
      background-color: red;
    }
  </style>
</head>

<body>

  <div class="box">
    <h1>Servo Motor Control</h1>

    <a href="/open">
      <button class="open">Open</button>
    </a>

    <a href="/close">
      <button class="close">Close</button>
    </a>
  </div>

</body>
</html>
)rawliteral";
}

void handleRoot() {
  server.send(200, "text/html", webpage());
}

void handleOpen() {
  myServo.write(90);

  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);

  server.send(200, "text/html", webpage());
}

void handleClose() {
  myServo.write(0);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);

  server.send(200, "text/html", webpage());
}

void setup() {

  Serial.begin(115200);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  myServo.setPeriodHertz(50);
  myServo.attach(SERVO_PIN, 500, 2400);

  myServo.write(0);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  Serial.println("WiFi Access Point Started");
  Serial.print("WiFi Name: ");
  Serial.println(ssid);

  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);
  server.on("/open", handleOpen);
  server.on("/close", handleClose);

  server.begin();

  Serial.println("Web Server Started");
}

void loop() {
  server.handleClient();

  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "open") {
      myServo.write(90);
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(RED_LED, LOW);
      Serial.println("OPEN");
    }

    if (command == "close") {
      myServo.write(0);
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(RED_LED, HIGH);
      Serial.println("CLOSE");
    }
  }
}
