float estimate = 0;
float estimate_error = 1;

float R = 100;
float Q = 0.01;

void setup() {
    Serial.begin(115200);

    pinMode(34, INPUT);
    pinMode(26, OUTPUT);

    digitalWrite(26, LOW);
}

void loop() {

    digitalWrite(26, LOW);
    delayMicroseconds(2);

    digitalWrite(26, HIGH);
    delayMicroseconds(10);

    digitalWrite(26, LOW);

    float duration = pulseIn(34, HIGH, 30000);
    float distance_cm = (0.0343 * duration) / 2;

    float prediction = estimate;   // Prediction is equal to previous estimated distance
    float prediction_error = estimate_error + Q;   // Predicting error value

    float K = prediction_error / (prediction_error + R);   // Kalman gain

    estimate = prediction + K * (distance_cm - prediction);   // Updated estimate

    estimate_error = (1 - K) * prediction_error;   // Updated error

    Serial.print("Calculated Distance (in cm): ");
    Serial.println(distance_cm);

    Serial.print("Filtered Distance (in cm): ");
    Serial.println(estimate);

    delay(60);
}
