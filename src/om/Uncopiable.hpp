#pragma once


namespace om
{
	class Uncopiable
	{
	public:
		Uncopiable() {}
		virtual ~Uncopiable() {}
	private:
		Uncopiable(Uncopiable const&);
		Uncopiable& operator=(Uncopiable const&);
	};
}
