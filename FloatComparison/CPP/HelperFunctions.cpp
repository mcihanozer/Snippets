// M. Cihan Ozer - November 2017

// Knuth D.E. The art of computer programming, vol II, section 4.2,
// especially Floating-Point Comparison 4.2.2, pages 198-220.
//
// Also: Boost library Floating-point Comparison page
bool approximatelyEqual(float a, float b)
{
    return std::fabsf(a - b) <= ( (std::fabsf(a) < std::fabsf(b) ? std::fabsf(b) : std::fabsf(a)) * std::numeric_limits<float>::epsilon() );
}

bool essentiallyEqual(float a, float b)
{
    return std::fabsf(a - b) <= ( (std::fabsf(a) > std::fabsf(b) ? std::fabsf(b) : std::fabsf(a)) * std::numeric_limits<float>::epsilon());
}

bool definitelyGreaterThan(float a, float b)
{
    return (a - b) > ( (std::fabsf(a) < std::fabsf(b) ? std::fabsf(b) :std::fabsf(a)) * std::numeric_limits<float>::epsilon());
}

bool definitelyLessThan(float a, float b)
{
    return (b - a) > ( (std::fabsf(a) < std::fabsf(b) ? std::fabsf(b) : std::fabsf(a)) * std::numeric_limits<float>::epsilon() );
}
