# kalman-distance-filter

An ESP32-based ultrasonic distance measurement system using a Kalman filter for smoother and more stable sensor readings.

This project was made to understand how filtering techniques can reduce noise in real-time sensor data. The ultrasonic sensor readings were often unstable, so a simple 1D Kalman filter was implemented to improve the estimation.

---

## Components Used

- ESP32
- Ultrasonic Sensor (HC-SR04)
- Arduino IDE

---

## How it Works

The ultrasonic sensor measures distance using echo pulse timing. Since raw readings fluctuate because of noise and environmental effects, a Kalman filter is applied to smooth the measurements.

The filter works by:
- predicting the next estimate
- calculating uncertainty
- updating the estimate using incoming sensor data

This produces a much more stable output compared to raw readings.

---

## Results

### Raw vs Kalman Filtered Distance

![Result 1](results1.png)

![Result 2](results2.png)

![Result 3](results3.png)

The filtered output converges gradually and significantly reduces fluctuations in sensor measurements.

---

## Running the Project

1. Connect the ultrasonic sensor to the ESP32
2. Upload the `.ino` file using Arduino IDE
3. Open Serial Monitor at `115200 baud`
4. Observe raw and filtered distance values

---

## Future Improvements

- Tune Kalman filter parameters dynamically
- Add OLED display support
- Real-time plotting dashboard
- Multi-sensor fusion
- Moving object tracking
