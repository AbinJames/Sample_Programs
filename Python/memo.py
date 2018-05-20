def memoise(fn):
	fn.cache={}
	def memoised_fn(n):
		if n in fn.cache:
			return fn.cache[n]
		else :
			ret=fn(n)
			fn.cache[n]=ret
			return ret
	return memoised_fn
	
