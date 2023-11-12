void splitString(const String& input, bool* booleanArray, int& length) {
    int inputLength = input.length();
    length = 0;
    int j=0;
    // Split the string into an array of boolean values
    for (int i = 0; i < inputLength; ++i) {
        if (input.charAt(i) == '1') {
            booleanArray[j++] = true;
        } else if (input.charAt(i) == '0') {
            booleanArray[j++] = false;
        }
    }

    length = j;
}

String joinWithComma(bool* bool_array, int length) {
    String result = "";

    for (int i = 0; i < length; ++i) {
        result += bool_array[i]?"true":"false";

        if (i < length - 1) {
            result += ",";
        }
    }

    return result;
}
