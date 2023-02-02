function square(x){
    return x * x;
 }
 console.log(square(2));
 console.log(square(4));

 function sum(x, y){
    return x + y;
 }
 console.log(sum(2, 3));
 console.log(sum(4, 5));

 function isPositive(x){
    if(x>0){
        return true;
    } else {
        return false;
    }
 }
 console.log(isPositive(2))
 console.log(isPositive(-2))

 function calculateArea(length, width){
    return length * width;
 }
 console.log(calculateArea(10, 5));

 function calculateVolume(length, width, height){
    return length * width * height;
 }
 console.log(calculateVolume(10, 5, 2));

 function convertCelsiusToFahrenheit(x){
    return x*1.800+32;
 }
 console.log(convertCelsiusToFahrenheit(0));