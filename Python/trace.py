def trace(fn):
	fn.indent=1
	def trace_fn(n):
		print " "*fn.indent,"|_____"+fn.___name___+"(%d)"%n
		fn.indent+=3
		ret = fn(n)
		fn.indent-=3
		return ret
	return trace_fn
	
