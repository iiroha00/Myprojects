let num = 99;
let string = '';
while(num>=2){
    string = num + " bottles of beer on the wall, " + num + " bottles of beer.";
    console.log(string);
    num--;
    if(num==1){
        string = "Take one down and pass it around, " + num + " bottle of beer on the wall.";
        console.log(string);
        string = num + " bottle of beer on the wall, " + num + " bottle of beer.";
        console.log(string);
        num--;
        string = "Take one down and pass it around, no more bottles of beer on the wall.";
        console.log(string);
        string = "No more bottles of beer on the wall, no more bottles of beer.";
        console.log(string);
        string = "Go to the store and buy some more, <99> bottles of beer on the wall.";
        console.log(string);
        break;
    }
    string = "Take one down and pass it around, " + num + " bottles of beer on the wall.";
    console.log(string);
}