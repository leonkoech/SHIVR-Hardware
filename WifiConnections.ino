const char *ssid = "1678";
const char *password = "12345678";
const int port = 1234;

const int input_length = 3;

WiFiServer server(port);

void SetupWifi(){
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting to WiFi... ");
    Serial.println(WiFi.status());
  }

  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void WifiLoop(){
  
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client connected");

    while (client.connected()) {
      // Check if data is available to read
      if (client.available() > 0) {
        // Read incoming data until a newline character is encountered
        String receivedData = client.readStringUntil('\n');

        int length;
        const int maxBooleans = 3; // Adjust this based on your requirements
        bool booleanArray[maxBooleans];
        Serial.println(receivedData);
    
        // Split the string into an array of boolean values
        splitString(receivedData, booleanArray, length);
        // Split the string into an array of boolean values
    
        if (booleanArray != NULL) {
            // Print the result
            int arrayLength = sizeof(booleanArray) / sizeof(booleanArray[0]);

            // Join the array elements with commas
            String result = joinWithComma(booleanArray, arrayLength);
            VibrationLoop(booleanArray, arrayLength);
            Serial.println(result);
    
        } else {
            printf("Memory allocation failed.\n");
        }

      }

      // Read data from sensors or other sources
      String dataToSend = "SensorData:123";

      // Send data to the connected client
      client.println(dataToSend); // Use println to send a newline-terminated message

//      delay(100); // Adjust the delay as needed
    }

    Serial.println("Client disconnected");
  }
  }
