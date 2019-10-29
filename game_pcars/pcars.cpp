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

	data->raceposition = racerInfo->mRacePosition;

	data->gear    = (uint8_t)m_pcarsData->mGear;
	data->rpm     = m_pcarsData->mRpm;
	data->rpm_max = m_pcarsData->mMaxRPM;
	data->speed   = (m_pcarsData->mSpeed * 3.6);
	data->fuel_level =
	    (m_pcarsData->mFuelLevel * m_pcarsData->mFuelCapacity);
	data->fuel_capacity = m_pcarsData->mFuelCapacity;

	data->tmp_oil   = m_pcarsData->mOilTempCelsius;
	data->tmp_water = m_pcarsData->mWaterTempCelsius;
	data->tmp_brake[eTYRE_FRONT_LEFT] =
	    m_pcarsData->mBrakeTempCelsius[TYRE_FRONT_LEFT];
	data->tmp_brake[eTYRE_FRONT_RIGHT] =
	    m_pcarsData->mBrakeTempCelsius[TYRE_FRONT_RIGHT];
	data->tmp_brake[eTYRE_REAR_LEFT] =
	    m_pcarsData->mBrakeTempCelsius[TYRE_REAR_LEFT];
	data->tmp_brake[eTYRE_REAR_RIGHT] =
	    m_pcarsData->mBrakeTempCelsius[TYRE_REAR_RIGHT];
	data->tmp_tyre[eTYRE_FRONT_LEFT] =
	    m_pcarsData->mTyreTemp[TYRE_FRONT_LEFT];
	data->tmp_tyre[eTYRE_FRONT_RIGHT] =
	    m_pcarsData->mTyreTemp[TYRE_FRONT_RIGHT];
	data->tmp_tyre[eTYRE_REAR_LEFT] =
	    m_pcarsData->mTyreTemp[TYRE_REAR_LEFT];
	data->tmp_tyre[eTYRE_REAR_RIGHT] =
	    m_pcarsData->mTyreTemp[TYRE_REAR_RIGHT];

	data->dmg_aero   = m_pcarsData->mAeroDamage * 100;
	data->dmg_engine = m_pcarsData->mEngineDamage * 100;
	data->dmg_brake[eTYRE_FRONT_LEFT] =
	    m_pcarsData->mBrakeDamage[TYRE_FRONT_LEFT] * 100;
	data->dmg_brake[eTYRE_FRONT_RIGHT] =
	    m_pcarsData->mBrakeDamage[TYRE_FRONT_RIGHT] * 100;
	data->dmg_brake[eTYRE_REAR_LEFT] =
	    m_pcarsData->mBrakeDamage[TYRE_REAR_LEFT] * 100;
	data->dmg_brake[eTYRE_REAR_RIGHT] =
	    m_pcarsData->mBrakeDamage[TYRE_REAR_RIGHT] * 100;
	data->dmg_suspension[eTYRE_FRONT_LEFT] =
	    m_pcarsData->mSuspensionDamage[TYRE_FRONT_LEFT] * 100;
	data->dmg_suspension[eTYRE_FRONT_RIGHT] =
	    m_pcarsData->mSuspensionDamage[TYRE_FRONT_RIGHT] * 100;
	data->dmg_suspension[eTYRE_REAR_LEFT] =
	    m_pcarsData->mSuspensionDamage[TYRE_REAR_LEFT] * 100;
	data->dmg_suspension[eTYRE_REAR_RIGHT] =
	    m_pcarsData->mSuspensionDamage[TYRE_REAR_RIGHT] * 100;
	data->dmg_tyre[eTYRE_FRONT_LEFT] =
	    m_pcarsData->mTyreWear[TYRE_FRONT_LEFT] * 100;
	data->dmg_tyre[eTYRE_FRONT_RIGHT] =
	    m_pcarsData->mTyreWear[TYRE_FRONT_RIGHT] * 100;
	data->dmg_tyre[eTYRE_REAR_LEFT] =
	    m_pcarsData->mTyreWear[TYRE_REAR_LEFT] * 100;
	data->dmg_tyre[eTYRE_REAR_RIGHT] =
	    m_pcarsData->mTyreWear[TYRE_REAR_RIGHT] * 100;

	data->time_bestlap     = m_pcarsData->mBestLapTime;
	data->time_lastlap     = m_pcarsData->mLastLapTime;
	data->time_splitahead  = m_pcarsData->mSplitTimeAhead;
	data->time_splitbehind = m_pcarsData->mSplitTimeBehind;

	return true;
}

bool Pcars::isRunning() {

	if (!m_sharedMemory.isAttached())
		m_sharedMemory.attach(QSharedMemory::ReadOnly);

	return m_sharedMemory.isAttached();
}
