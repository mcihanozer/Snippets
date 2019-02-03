// M. Cihan Ozer - 2019

using System;
using TN_Commons.TN_SuperPowers;

// Base class for super powers in Tap Nations.
// Provides necessary members and methods
public abstract class TN_SuperPower : TN_SuperPowerComponent.TN_BaseSuperPower
{
	public enum eSuperPowerHitType
	{
        Count, Damage, Once, Second, 
	};

	protected bool isActive;
	protected readonly eSuperPowerHitType hitType;
	protected readonly eSuperPowerTypes superPowerType;
	//protected readonly float powerLevel;  // Power level is moved to TN_BaseSuperPower for mimicing the friendship in C#
                                            // Refer TN_SuperPowerComponent.cs for more details.
	protected readonly float powerParameter;

    protected float currentParameterValue;
    protected readonly float thresholdValue;

    // This is a hook method used to evaluate the life time of the super powers with different requirements,
    // i.e., Second type super powers decrease the current parameter value by the delta time, Count type
    // super powers decrease the current parameter value by the count decrease value and so on.
    protected abstract void EvaluatePowerLifeTime();

    public TN_SuperPower(eSuperPowerHitType hitType, eSuperPowerTypes powerType, float powerLevel, float powerParameter, float thresholdValue)
    {
        this.hitType = hitType;
        this.superPowerType = powerType;
        this.powerLevel = powerLevel;
        this.powerParameter = powerParameter;
        this.thresholdValue = thresholdValue;
    }
    
    // Setters - getters
    // Some related methods
}
