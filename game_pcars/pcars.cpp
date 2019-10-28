#include "pcars.h"

#define MEMORY_KEY "$pcars$"

Pcars::Pcars() {
	m_sharedMemory.setNativeKey(MEMORY_KEY);
	m_sharedMemory.attach(QSharedMemory::ReadOnly);

	m_pcarsData =
	    reinterpret_cast<MemoryMap_Pcars *>(m_sharedMemory.data());
}

bool Pcars::writeDataTo(gamedata *data) {
	if (!isRunning())
		return false;

	ParticipantInfo *racerInfo = m_pcarsData->mParticipantInfo;

	data->racePosition = racerInfo->mRacePosition;

	data->gear   = (uint8_t)m_pcarsData->mGear;
	data->rpm    = m_pcarsData->mRpm;
	data->maxRpm = m_pcarsData->mMaxRPM;
	data->speed  = (m_pcarsData->mSpeed * 3.6);
	data->fuelLevel =
	    (m_pcarsData->mFuelLevel * m_pcarsData->mFuelCapacity);
	data->fuelCapacity = m_pcarsData->mFuelCapacity;

	data->tempOil   = m_pcarsData->mOilTempCelsius;
	data->tempWater = m_pcarsData->mWaterTempCelsius;
	data->tempBrake[eTYRE_FRONT_LEFT] =
	    m_pcarsData->mBrakeTempCelsius[TYRE_FRONT_LEFT];
	data->tempBrake[eTYRE_FRONT_RIGHT] =
	    m_pcarsData->mBrakeTempCelsius[TYRE_FRONT_RIGHT];
	data->tempBrake[eTYRE_REAR_LEFT] =
	    m_pcarsData->mBrakeTempCelsius[TYRE_REAR_LEFT];
	data->tempBrake[eTYRE_REAR_RIGHT] =
	    m_pcarsData->mBrakeTempCelsius[TYRE_REAR_RIGHT];
	data->tempTyre[eTYRE_FRONT_LEFT] =
	    m_pcarsData->mTyreTemp[TYRE_FRONT_LEFT];
	data->tempTyre[eTYRE_FRONT_RIGHT] =
	    m_pcarsData->mTyreTemp[TYRE_FRONT_RIGHT];
	data->tempTyre[eTYRE_REAR_LEFT] =
	    m_pcarsData->mTyreTemp[TYRE_REAR_LEFT];
	data->tempTyre[eTYRE_REAR_RIGHT] =
	    m_pcarsData->mTyreTemp[TYRE_REAR_RIGHT];

	data->damageAero   = m_pcarsData->mAeroDamage * 100;
	data->damageEngine = m_pcarsData->mEngineDamage * 100;
	data->damageBrake[eTYRE_FRONT_LEFT] =
	    m_pcarsData->mBrakeDamage[TYRE_FRONT_LEFT] * 100;
	data->damageBrake[eTYRE_FRONT_RIGHT] =
	    m_pcarsData->mBrakeDamage[TYRE_FRONT_RIGHT] * 100;
	data->damageBrake[eTYRE_REAR_LEFT] =
	    m_pcarsData->mBrakeDamage[TYRE_REAR_LEFT] * 100;
	data->damageBrake[eTYRE_REAR_RIGHT] =
	    m_pcarsData->mBrakeDamage[TYRE_REAR_RIGHT] * 100;
	data->damageSuspension[eTYRE_FRONT_LEFT] =
	    m_pcarsData->mSuspensionDamage[TYRE_FRONT_LEFT] * 100;
	data->damageSuspension[eTYRE_FRONT_RIGHT] =
	    m_pcarsData->mSuspensionDamage[TYRE_FRONT_RIGHT] * 100;
	data->damageSuspension[eTYRE_REAR_LEFT] =
	    m_pcarsData->mSuspensionDamage[TYRE_REAR_LEFT] * 100;
	data->damageSuspension[eTYRE_REAR_RIGHT] =
	    m_pcarsData->mSuspensionDamage[TYRE_REAR_RIGHT] * 100;
	data->damageTyre[eTYRE_FRONT_LEFT] =
	    m_pcarsData->mTyreWear[TYRE_FRONT_LEFT] * 100;
	data->damageTyre[eTYRE_FRONT_RIGHT] =
	    m_pcarsData->mTyreWear[TYRE_FRONT_RIGHT] * 100;
	data->damageTyre[eTYRE_REAR_LEFT] =
	    m_pcarsData->mTyreWear[TYRE_REAR_LEFT] * 100;
	data->damageTyre[eTYRE_REAR_RIGHT] =
	    m_pcarsData->mTyreWear[TYRE_REAR_RIGHT] * 100;

	data->timeBestLap	= m_pcarsData->mBestLapTime;
	data->timeLastLap	= m_pcarsData->mLastLapTime;
	data->timeCurrentSector1 = m_pcarsData->mCurrentSector1Time;
	data->timeCurrentSector2 = m_pcarsData->mCurrentSector2Time;
	data->timeCurrentSector3 = m_pcarsData->mCurrentSector3Time;
	data->timeFastestSector1 = m_pcarsData->mFastestSector1Time;
	data->timeFastestSector2 = m_pcarsData->mFastestSector2Time;
	data->timeFastestSector3 = m_pcarsData->mFastestSector3Time;
	data->timeSplitAhead     = m_pcarsData->mSplitTimeAhead;
	data->timeSplitBehind    = m_pcarsData->mSplitTimeBehind;

	return true;
}

bool Pcars::isRunning() {

	if (!m_sharedMemory.isAttached())
		m_sharedMemory.attach(QSharedMemory::ReadOnly);

	return m_sharedMemory.isAttached();
}
