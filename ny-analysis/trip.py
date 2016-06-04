class Trip:

	def __init__(self, trip_id=None, pickup=None, dropoff=None, pickup_time=None, dropoff_time=None, payment_method=None):
		self.trip_id = trip_id
		self.pickup = pickup
		self.dropoff = dropoff
		self.pickup_time = pickup_time
		self.dropoff_time = dropoff_time
		self.payment_method = payment_method