

var val1 = parseInt(document.getElementById("box1").value);
var val2 = parseInt(document.getElementById("box2").value);

function Add() {
  document.getElementById("box3").value = val1 + val2;
}
function Sub() {
  document.getElementById("box3").value = val1 - val2;
}
function Mult() {
  document.getElementById("box3").value = val1 * val2;
}
function Div() {
  document.getElementById("box3").value = val1 / val2;
}
setTimeout(function(){
  document.getElementById("box3").value ="";
},5000);