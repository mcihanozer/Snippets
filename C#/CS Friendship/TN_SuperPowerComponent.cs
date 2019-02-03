// M. Cihan Ozer - February 2019

using System.Collections.Generic;
using TN_Commons.TN_SuperPowers;

// A wrapper and manager class for Tap Nations' super power.
//
// TN_SuperPowerComponent receives from super power event managers and creates
// related events to manage related game components.
//
// Holds all the super powers possible and service the active ones.
public class TN_SuperPowerComponent
{
    // Private interface for mimicing C++ friendship
    // GOOD EXAMPLE: https://stackoverflow.com/a/37238655/1572782
    //
    // Super power level can change during the game via the related UI.
    // We can make aware TN_SuperPowerComponent via an event; however,
    // we still need a mechanism to update the level of the related super
    // power. In this sense, having a setter is not safe and other classes
    // do not and should not need to touch or reach this setter. Since, C#
    // does not have friendship as C++, we need to mimic this via private
    // interfaces.
    private interface IFriendshipForSuperPower
    {
        void SetPowerLevel(float newLevel);
    }

    public abstract class TN_BaseSuperPower : IFriendshipForSuperPower
    {
        protected float powerLevel;

        // We will still need casting to IFriendshipForSuperPower for
        // being able to reach this method.
        void IFriendshipForSuperPower.SetPowerLevel(float newLevel)
        {
            powerLevel = newLevel;
        }
    }

    private TN_SuperPower[] superPowers = new TN_SuperPower[(uint)eSuperPowerTypes.COUNT];
    
    private void UpgradePowerLevel(eSuperPowerTypes power, float newLevel)
    {
        var index = TN_SuperPowerHelpers.ConvertSuperPowerEnumToInt(power);
        ( (IFriendshipForSuperPower)superPowers[index] ).SetPowerLevel(newLevel);
    }
}
