// M. Cihan Ozer - June 2018

using UnityEngine; // A bit of Unity dependency

namespace FloatComparisonHelper
{
	public class FloatComparison
	{
		// Knuth D.E. The art of computer programming, vol II, section 4.2,
		// especially Floating-Point Comparison 4.2.2, pages 198-220.
        //
		// Also: Boost library Floating-point Comparison page

		public static bool approximatelyEqual(float a, float b)
    	{
			return Mathf.Abs(a - b) <= ((Mathf.Abs(a) < Mathf.Abs(b) ? Mathf.Abs(b) : Mathf.Abs(a)) * Mathf.Epsilon);
    	}

		public static bool essentiallyEqual(float a, float b)
    	{
			return Mathf.Abs(a - b) <= ((Mathf.Abs(a) > Mathf.Abs(b) ? Mathf.Abs(b) : Mathf.Abs(a)) * Mathf.Epsilon);
    	}

		public static bool definitelyGreaterThan(float a, float b)
    	{
			return (a - b) > ((Mathf.Abs(a) < Mathf.Abs(b) ? Mathf.Abs(b) : Mathf.Abs(a)) * Mathf.Epsilon);
    	}

		public static bool definitelyLessThan(float a, float b)
    	{
			return (b - a) > ((Mathf.Abs(a) < Mathf.Abs(b) ? Mathf.Abs(b) : Mathf.Abs(a)) * Mathf.Epsilon);
    	}
	}
}
