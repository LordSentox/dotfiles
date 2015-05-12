#ifndef CONTEXT_HPP
#define CONTEXT_HPP

//-------------------------------------------
// Context provides support of variables in a
// broader context than the statement itself.
//-------------------------------------------
class Context
{
public:
	Context ();
	virtual ~Context () = default;
};

#endif
