function placeAnOrder(orderNumber) {
	console.log("Customer order:", orderNumber);

	cookAndDeliverFood(function () {
		console.log("Deliver food order: ", orderNumber);
	});
}

// Simulate a 5 second operation
function cookAndDeliverFood(callback) {
	setTimeOut(callback, 5000);
}

// Simulate users web request
