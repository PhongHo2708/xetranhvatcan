// Khai báo các chân cho động cơ
const int motor1Pin1 = 2;
const int motor1Pin2 = 3;
const int motor2Pin1 = 4;
const int motor2Pin2 = 5;
const int enable1Pin = 6;
const int enable2Pin = 7;

// Khai báo các chân cho cảm biến siêu âm
const int trigPin = 9;
const int echoPin = 10;

// Khai báo biến để lưu trữ thời gian và khoảng cách
long duration;
int distance;

void setup() {
  // Thiết lập các chân động cơ là đầu ra
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(enable2Pin, OUTPUT);

  // Thiết lập các chân cảm biến siêu âm
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Khởi động Serial Monitor
  Serial.begin(9600);

  // Bật động cơ
  digitalWrite(enable1Pin, HIGH);
  digitalWrite(enable2Pin, HIGH);
}

void loop() {
  // Gửi xung siêu âm từ chân Trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Đo thời gian xung phản hồi
  duration = pulseIn(echoPin, HIGH);

  // Tính khoảng cách từ thời gian xung
  distance = duration * 0.034 / 2;

  // In khoảng cách lên Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  // Kiểm tra khoảng cách để điều khiển xe
  if (distance < 20) {
    // Nếu có vật cản gần, lùi lại và rẽ phải
    moveBackward();
    delay(500);
    turnRight();
    delay(500);
  } else {
    // Nếu không có vật cản, đi thẳng
    moveForward();
  }
}

// Hàm điều khiển xe tiến lên
void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

// Hàm điều khiển xe lùi lại
void moveBackward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

// Hàm điều khiển xe rẽ phải
void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

// Hàm điều khiển xe rẽ trái
void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}
