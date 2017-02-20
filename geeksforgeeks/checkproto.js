function foo(){
	this.hello = "bhag salle";
}

foo.prototype={
	kutta:"helj"
}
var obj= new foo();
console.log(Object.getPrototypeOf(obj));