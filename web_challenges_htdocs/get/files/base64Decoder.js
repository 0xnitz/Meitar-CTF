/*
 * JavaScript code that prompt the user for a Base-64 encoded string, and outputs the decoded result.
 *
 * Author: thatHexa
 */

function decodeFromBase64(stringToDecode) {
  return atob(stringToDecode);
}

const userInput = prompt('Enter a Base-64 string to decode:');
const decodedString = decodeFromBase64(userInput);
alert(decodedString);
