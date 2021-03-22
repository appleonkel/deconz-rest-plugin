/*
 * Copyright (c) 2017-2020 dresden elektronik ingenieurtechnik gmbh.
 * All rights reserved.
 *
 * The software in this package is published under the terms of the BSD
 * style license a copy of which has been included with this distribution in
 * the LICENSE.txt file.
 *
 */

#include <QString>
#include <QJSEngine>
#include "deconz.h"
#include "resource.h"
#include "tuya.h"
#include "de_web_plugin_private.h"

const char *RDevices = "/devices";
const char *RSensors = "/sensors";
const char *RLights = "/lights";
const char *RGroups = "/groups";
const char *RConfig = "/config";

const char *REventAdded = "event/added";
const char *REventAwake = "event/awake";
const char *REventBindingTable = "event/binding.table";
const char *REventBindingTick = "event/binding.tick";
const char *REventDeleted = "event/deleted";
const char *REventPoll = "event/poll";
const char *REventValidGroup = "event/validgroup";
const char *REventCheckGroupAnyOn = "event/checkgroupanyon";
const char *REventNodeDescriptor = "event/node.descriptor";
const char *REventActiveEndpoints = "event/active.endpoints";
const char *REventSimpleDescriptor = "event/simple.descriptor";
const char *REventStateEnter = "event/state.enter";
const char *REventStateLeave = "event/state.leave";
const char *REventStateTimeout = "event/state.timeout";
const char *REventTick = "event/tick";

const char *RInvalidSuffix = "invalid/suffix";

const char *RAttrName = "attr/name";
const char *RAttrManufacturerName = "attr/manufacturername";
const char *RAttrModelId = "attr/modelid";
const char *RAttrType = "attr/type";
const char *RAttrClass = "attr/class";
const char *RAttrId = "attr/id";
const char *RAttrUniqueId = "attr/uniqueid";
const char *RAttrProductId = "attr/productid";
const char *RAttrSwVersion = "attr/swversion";
const char *RAttrLastAnnounced = "attr/lastannounced";
const char *RAttrLastSeen = "attr/lastseen";
const char *RAttrExtAddress = "attr/extaddress";
const char *RAttrNwkAddress = "attr/nwkaddress";
const char *RAttrGroupAddress = "attr/groupaddress";

const char *RActionScene = "action/scene";

const char *RStateAirQuality = "state/airquality";
const char *RStateAirQualityPpb = "state/airqualityppb";
const char *RStateAlarm = "state/alarm";
const char *RStateAlert = "state/alert";
const char *RStateAllOn = "state/all_on";
const char *RStateAngle = "state/angle";
const char *RStateAnyOn = "state/any_on";
const char *RStateBattery = "state/battery";
const char *RStateBri = "state/bri";
const char *RStateButtonEvent = "state/buttonevent";
const char *RStateCarbonMonoxide = "state/carbonmonoxide";
const char *RStateColorMode = "state/colormode";
const char *RStateConsumption = "state/consumption";
const char *RStateCurrent = "state/current";
const char *RStateCt = "state/ct";
const char *RStateDark = "state/dark";
const char *RStateDaylight = "state/daylight";
const char *RStateEffect = "state/effect";
const char *RStateErrorCode = "state/errorcode";
const char *RStateEventDuration = "state/eventduration";
const char *RStateFire = "state/fire";
const char *RStateFlag = "state/flag";
const char *RStateFloorTemperature = "state/floortemperature";
const char *RStateGesture = "state/gesture";
const char *RStateHeating = "state/heating";
const char *RStateHue = "state/hue";
const char *RStateHumidity = "state/humidity";
const char *RStateLastCheckin = "state/lastcheckin";
const char *RStateLastSet = "state/lastset";
const char *RStateLastUpdated = "state/lastupdated";
const char *RStateLift = "state/lift";
const char *RStateLightLevel = "state/lightlevel";
const char *RStateLowBattery = "state/lowbattery";
const char *RStateLocaltime = "state/localtime";
const char *RStateLux = "state/lux";
const char *RStateMountingModeActive = "state/mountingmodeactive";
const char *RStateOn = "state/on";
const char *RStateOpen = "state/open";
const char *RStateOrientationX = "state/orientation_x";
const char *RStateOrientationY = "state/orientation_y";
const char *RStateOrientationZ = "state/orientation_z";
const char *RStatePresence = "state/presence";
const char *RStatePressure = "state/pressure";
const char *RStatePower = "state/power";
const char *RStateReachable = "state/reachable";
const char *RStateSat = "state/sat";
const char *RStateSpectralX = "state/spectral_x";
const char *RStateSpectralY = "state/spectral_y";
const char *RStateSpectralZ = "state/spectral_z";
const char *RStateSpeed = "state/speed";
const char *RStateStatus = "state/status";
const char *RStateSunrise = "state/sunrise";
const char *RStateSunset = "state/sunset";
const char *RStateUtc = "state/utc";
const char *RStateTampered = "state/tampered";
const char *RStateTemperature = "state/temperature";
const char *RStateTest = "state/test";
const char *RStateTilt = "state/tilt";
const char *RStateTiltAngle = "state/tiltangle";
const char *RStateValve = "state/valve";
const char *RStateVibration = "state/vibration";
const char *RStateVibrationStrength = "state/vibrationstrength";
const char *RStateVoltage = "state/voltage";
const char *RStateWater = "state/water";
const char *RStateWindowOpen = "state/windowopen";
const char *RStateX = "state/x";
const char *RStateY = "state/y";

const QStringList RStateEffectValues({
    "none", "colorloop"
});
const QStringList RStateEffectValuesMueller({
    "none", "colorloop", "sunset", "party", "worklight", "campfire", "romance", "nightlight"
});

const char *RConfigAlert = "config/alert";
const char *RConfigBattery = "config/battery";
const char *RConfigColorCapabilities = "config/colorcapabilities";
const char *RConfigCtMin = "config/ctmin";
const char *RConfigCtMax = "config/ctmax";
const char *RConfigCheckin = "config/checkin";
const char *RConfigConfigured = "config/configured";
const char *RConfigCoolSetpoint = "config/coolsetpoint";
const char *RConfigDelay = "config/delay";
const char *RConfigDeviceMode = "config/devicemode";
const char *RConfigDisplayFlipped = "config/displayflipped";
const char *RConfigDuration = "config/duration";
const char *RConfigEnrolled = "config/enrolled";
const char *RConfigFanMode = "config/fanmode";
const char *RConfigGroup = "config/group";
const char *RConfigHeatSetpoint = "config/heatsetpoint";
const char *RConfigHostFlags = "config/hostflags";
const char *RConfigId = "config/id";
const char *RConfigLastChangeAmount = "config/lastchange_amount";
const char *RConfigLastChangeSource = "config/lastchange_source";
const char *RConfigLastChangeTime = "config/lastchange_time";
const char *RConfigLat = "config/lat";
const char *RConfigLedIndication = "config/ledindication";
const char *RConfigLocalTime = "config/localtime";
const char *RConfigLocked = "config/locked";
const char *RConfigLong = "config/long";
const char *RConfigLevelMin = "config/levelmin";
const char *RConfigMode = "config/mode";
const char *RConfigSetValve = "config/setvalve";
const char *RConfigMountingMode = "config/mountingmode";
const char *RConfigExternalTemperatureSensor = "config/externalsensortemp";
const char *RConfigExternalWindowOpen = "config/externalwindowopen";
const char *RConfigOffset = "config/offset";
const char *RConfigOn = "config/on";
const char *RConfigPending = "config/pending";
const char *RConfigPowerup = "config/powerup";
const char *RConfigPowerOnCt = "config/poweronct";
const char *RConfigPowerOnLevel = "config/poweronlevel";
const char *RConfigPreset = "config/preset";
const char *RConfigMelody = "config/melody";
const char *RConfigVolume = "config/volume";
const char *RConfigTempThreshold = "config/temperaturethreshold";
const char *RConfigHumiThreshold = "config/humiditythreshold";
const char *RConfigReachable = "config/reachable";
const char *RConfigSchedule = "config/schedule";
const char *RConfigScheduleOn = "config/schedule_on";
const char *RConfigSensitivity = "config/sensitivity";
const char *RConfigSensitivityMax = "config/sensitivitymax";
const char *RConfigSunriseOffset = "config/sunriseoffset";
const char *RConfigSunsetOffset = "config/sunsetoffset";
const char *RConfigSwingMode = "config/swingmode";
const char *RConfigTemperature = "config/temperature";
const char *RConfigTemperatureMeasurement = "config/temperaturemeasurement";
const char *RConfigTholdDark = "config/tholddark";
const char *RConfigTholdOffset = "config/tholdoffset";
const char *RConfigUrl = "config/url";
const char *RConfigUsertest = "config/usertest";
const char *RConfigWindowCoveringType = "config/windowcoveringtype";
const char *RConfigWindowOpen = "config/windowopen_set";
const char *RConfigUbisysJ1Mode = "config/ubisys_j1_mode";
const char *RConfigUbisysJ1WindowCoveringType = "config/ubisys_j1_windowcoveringtype";
const char *RConfigUbisysJ1ConfigurationAndStatus = "config/ubisys_j1_configurationandstatus";
const char *RConfigUbisysJ1InstalledOpenLimitLift = "config/ubisys_j1_installedopenlimitlift";
const char *RConfigUbisysJ1InstalledClosedLimitLift = "config/ubisys_j1_installedclosedlimitlift";
const char *RConfigUbisysJ1InstalledOpenLimitTilt = "config/ubisys_j1_installedopenlimittilt";
const char *RConfigUbisysJ1InstalledClosedLimitTilt = "config/ubisys_j1_installedclosedlimittilt";
const char *RConfigUbisysJ1TurnaroundGuardTime = "config/ubisys_j1_turnaroundguardtime";
const char *RConfigUbisysJ1LiftToTiltTransitionSteps = "config/ubisys_j1_lifttotilttransitionsteps";
const char *RConfigUbisysJ1TotalSteps = "config/ubisys_j1_totalsteps";
const char *RConfigUbisysJ1LiftToTiltTransitionSteps2 = "config/ubisys_j1_lifttotilttransitionsteps2";
const char *RConfigUbisysJ1TotalSteps2 = "config/ubisys_j1_totalsteps2";
const char *RConfigUbisysJ1AdditionalSteps = "config/ubisys_j1_additionalsteps";
const char *RConfigUbisysJ1InactivePowerThreshold = "config/ubisys_j1_inactivepowerthreshold";
const char *RConfigUbisysJ1StartupSteps = "config/ubisys_j1_startupsteps";

const QStringList RConfigDeviceModeValues({
    "singlerocker", "singlepushbutton", "dualrocker", "dualpushbutton"
});

const QStringList RConfigLastChangeSourceValues({
    "manual", "schedule", "zigbee"
});

static std::vector<const char*> rPrefixes;
static std::vector<ResourceItemDescriptor> rItemDescriptors;
static const QString rInvalidString; // is returned when string is asked but not available
const ResourceItemDescriptor rInvalidItemDescriptor(DataTypeUnknown, RInvalidSuffix);

/*! A generic function to parse ZCL values from read/report commands.
    The item->parseParameters() is expected to contain 5 elements (given in the device description file).

    ["parseGenericAttribute/4", endpoint, clusterId, attributeId, expression]

    - endpoint, 0xff means any endpoint
    - clusterId: string hex value
    - attributeId: string hex value
    - expression: Javascript expression to transform the raw value

    Example: { "parse": ["parseGenericAttribute/4", 1, "0x0402", "0x0000", "$raw + $config/offset"] }
 */
bool parseGenericAttribute4(Resource *r, ResourceItem *item, const deCONZ::ApsDataIndication &ind, const deCONZ::ZclFrame &zclFrame)
{
    Q_UNUSED(r)

    bool result = false;

    if (zclFrame.commandId() != deCONZ::ZclReadAttributesResponseId && zclFrame.commandId() != deCONZ::ZclReportAttributesId)
    {
        return result;
    }

    if (!item->parseFunction()) // init on first call
    {
        Q_ASSERT(item->parseParameters().size() == 5);
        if (item->parseParameters().size() != 5)
        {
            return result;
        }
        bool ok;
        const auto endpoint = item->parseParameters().at(1).toString().toUInt(&ok, 0);
        const auto clusterId = ok ? item->parseParameters().at(2).toString().toUInt(&ok, 0) : 0;
        const auto attributeId = ok ? item->parseParameters().at(3).toString().toUInt(&ok, 0) : 0;

        if (!ok)
        {
            return result;
        }

        item->setParseFunction(parseGenericAttribute4);
        item->setZclProperties(clusterId, attributeId, endpoint);
    }

    if (ind.clusterId() != item->clusterId() || zclFrame.payload().isEmpty())
    {
        return result;
    }

    if (item->endpoint() < 0xff && item->endpoint() != ind.srcEndpoint())
    {
        return result;
    }

    QDataStream stream(zclFrame.payload());
    stream.setByteOrder(QDataStream::LittleEndian);

    while (!stream.atEnd())
    {
        quint16 attrId;
        quint8 status;
        quint8 dataType;

        stream >> attrId;

        if (zclFrame.commandId() == deCONZ::ZclReadAttributesResponseId)
        {
            stream >> status;
            if (status != deCONZ::ZclSuccessStatus)
            {
                continue;
            }
        }

        stream >> dataType;
        deCONZ::ZclAttribute attr(attrId, dataType, QLatin1String(""), deCONZ::ZclReadWrite, true);

        if (!attr.readFromStream(stream))
        {
            break;
        }

        if (attrId == item->attributeId())
        {
            auto expr = item->parseParameters().back().toString();

            if (expr.contains(QLatin1String("$old")) && dataType < deCONZ::ZclOctedString)
            {
                expr.replace("$old", QString::number(item->toNumber()));
            }

            if (expr == QLatin1String("$raw"))
            {
                if (item->setValue(attr.toVariant(), ResourceItem::SourceDevice))
                {
                    result = true;
                }

                DBG_Printf(DBG_INFO, "RD cluster: 0x%04X / %04X --> %s\n", ind.clusterId(), attrId, qPrintable(attr.toString()));
            }
            else if (expr.contains(QLatin1String("$raw")) && dataType < deCONZ::ZclOctedString) // numeric data type
            {
                if ((dataType >= deCONZ::Zcl8BitData && dataType <= deCONZ::Zcl64BitUint)
                     || dataType == deCONZ::Zcl8BitEnum || dataType == deCONZ::Zcl16BitEnum)
                {
                    expr.replace("$raw", QString::number(attr.numericValue().u64));
                }
                else if (dataType >= deCONZ::Zcl8BitInt && dataType <= deCONZ::Zcl64BitInt)
                {
                    expr.replace("$raw", QString::number(attr.numericValue().s64));
                }
                else if (dataType >= deCONZ::ZclSemiFloat && dataType <= deCONZ::ZclDoubleFloat)
                {
                    expr.replace("$raw", QString::number(attr.numericValue().real));
                }
                else
                {
                    return result;
                }

                QJSEngine engine;

                const auto res = engine.evaluate(expr);

                if (!res.isError())
                {
                    DBG_Printf(DBG_INFO, "expression: %s = %.0f\n", qPrintable(expr), res.toNumber());
                    item->setValue(res.toVariant(), ResourceItem::SourceDevice);
                    result = true;
                }
                else
                {
                    DBG_Printf(DBG_INFO, "failed to evaluate expression: %s, err: %d\n", qPrintable(expr), res.errorType());
                }
            }
            break;
        }
    }

    return result;
}

/*! A generic function to read ZCL attributes.
    The item->readParameters() is expected to contain 5 elements (given in the device description file).

    ["readGenericAttribute/4", endpoint, clusterId, attributeId, manufacturerCode]

    - endpoint, 0xff means any endpoint
    - clusterId: string hex value
    - attributeId: string hex value
    - manufacturerCode: must be set to 0x0000 for non manufacturer specific commands

    Example: { "read": ["readGenericAttribute/4", 1, "0x0402", "0x0000", "0x110b"] }
 */
bool readGenericAttribute4(const Resource *r, const ResourceItem *item, deCONZ::ApsController *apsCtrl)
{
    bool result = false;
    Q_ASSERT(item->readParameters().size() == 5);
    if (item->readParameters().size() != 5)
    {
        return result;
    }

    const auto *extAddr = r->item(RAttrExtAddress);
    const auto *nwkAddr = r->item(RAttrNwkAddress);

    if (!extAddr || !nwkAddr)
    {
        return result;
    }

    bool ok;
    const auto endpoint = item->readParameters().at(1).toString().toUInt(&ok, 0);
    const auto clusterId = ok ? item->readParameters().at(2).toString().toUInt(&ok, 0) : 0;
    const auto attributeId = ok ? item->readParameters().at(3).toString().toUInt(&ok, 0) : 0;
    const auto manufacturerCode = ok ? item->readParameters().at(4).toString().toUInt(&ok, 0) : 0;

    if (!ok)
    {
        return result;
    }

    DBG_Printf(DBG_INFO, "readGenericAttribute/4, ep: 0x%02X, cl: 0x%04X, attr: 0x%04X, mfcode: 0x%04X\n", endpoint, clusterId, attributeId, manufacturerCode);

    const std::vector<quint16> attributes = { static_cast<quint16>(attributeId) };


//    task.req.setTxOptions(deCONZ::ApsTxAcknowledgedTransmission);
    deCONZ::ApsDataRequest req;
    req.setDstEndpoint(endpoint);
    req.setDstAddressMode(deCONZ::ApsExtAddress);
    req.dstAddress().setExt(extAddr->toNumber());
    req.dstAddress().setNwk(nwkAddr->toNumber());
    req.setClusterId(clusterId);
    req.setProfileId(HA_PROFILE_ID);
    req.setSrcEndpoint(0x01); // todo dynamic

    deCONZ::ZclFrame zclFrame;

    zclFrame.setSequenceNumber(zclNextSequenceNumber());
    zclFrame.setCommandId(deCONZ::ZclReadAttributesId);

    if (manufacturerCode)
    {
        zclFrame.setFrameControl(deCONZ::ZclFCProfileCommand |
                                      deCONZ::ZclFCManufacturerSpecific |
                                      deCONZ::ZclFCDirectionClientToServer |
                                      deCONZ::ZclFCDisableDefaultResponse);
        zclFrame.setManufacturerCode(manufacturerCode);
    }
    else
    {
        zclFrame.setFrameControl(deCONZ::ZclFCProfileCommand |
                                      deCONZ::ZclFCDirectionClientToServer |
                                      deCONZ::ZclFCDisableDefaultResponse);
    }

    { // payload
        QDataStream stream(&zclFrame.payload(), QIODevice::WriteOnly);
        stream.setByteOrder(QDataStream::LittleEndian);

        for (uint i = 0; i < attributes.size(); i++)
        {
            stream << attributes[i];
        }
    }


    { // ZCL frame
        QDataStream stream(&req.asdu(), QIODevice::WriteOnly);
        stream.setByteOrder(QDataStream::LittleEndian);
        zclFrame.writeToStream(stream);
    }

    if (apsCtrl->apsdeDataRequest(req) == deCONZ::Success)
    {
        result = true;
    }
    else
    {

    }

    return result;
}

/*! A generic function to write ZCL attributes.
    The item->writeParameters() is expected to contain 7 elements (given in the device description file).

    ["writeGenericAttribute/6", endpoint, clusterId, attributeId, zclDataType, manufacturerCode, expression]

    - endpoint: the destination endpoint
    - clusterId: string hex value
    - attributeId: string hex value
    - zclDataType: string hex value
    - manufacturerCode: must be set to 0x0000 for non manufacturer specific commands
    - expression: to transform the item value

    Example: { "write": ["writeGenericAttribute/6", 1, "0x0020", "0x0000", "0x23", "0x0000", "$raw"] }
 */
bool writeGenericAttribute6(const Resource *r, const ResourceItem *item, deCONZ::ApsController *apsCtrl)
{
    Q_ASSERT(r);
    Q_ASSERT(item);
    Q_ASSERT(apsCtrl);

    bool result = false;
    Q_ASSERT(item->writeParameters().size() == 7);
    if (item->writeParameters().size() != 7)
    {
        return result;
    }

    const auto rParent = r->parentResource() ? r->parentResource() : r;
    const auto *extAddr = rParent->item(RAttrExtAddress);
    const auto *nwkAddr = rParent->item(RAttrNwkAddress);

    if (!extAddr || !nwkAddr)
    {
        return result;
    }

    bool ok;
    const auto endpoint = item->writeParameters().at(1).toString().toUInt(&ok, 0);
    const auto clusterId = ok ? item->writeParameters().at(2).toString().toUInt(&ok, 0) : 0;
    const auto attributeId = ok ? item->writeParameters().at(3).toString().toUInt(&ok, 0) : 0;
    const auto dataType = ok ? item->writeParameters().at(4).toString().toUInt(&ok, 0) : 0;
    const auto manufacturerCode = ok ? item->writeParameters().at(5).toString().toUInt(&ok, 0) : 0;
    auto expr = item->writeParameters().back().toString();

    if (!ok)
    {
        return result;
    }

    DBG_Printf(DBG_INFO, "writeGenericAttribute/6, ep: 0x%02X, cl: 0x%04X, attr: 0x%04X, type: 0x%02X, mfcode: 0x%04X, expr: %s\n", endpoint, clusterId, attributeId, dataType, manufacturerCode, qPrintable(expr));

    const std::vector<quint16> attributes = { static_cast<quint16>(attributeId) };


    deCONZ::ApsDataRequest req;
    deCONZ::ZclFrame zclFrame;

    req.setDstEndpoint(endpoint);
    req.setTxOptions(deCONZ::ApsTxAcknowledgedTransmission);
    req.setDstAddressMode(deCONZ::ApsNwkAddress);
    req.dstAddress().setNwk(nwkAddr->toNumber());
    req.dstAddress().setExt(extAddr->toNumber());
    req.setClusterId(clusterId);
    req.setProfileId(HA_PROFILE_ID);
    req.setSrcEndpoint(1); // TODO

    zclFrame.setSequenceNumber(zclNextSequenceNumber());
    zclFrame.setCommandId(deCONZ::ZclWriteAttributesId);

    if (manufacturerCode)
    {
        zclFrame.setFrameControl(deCONZ::ZclFCProfileCommand |
                                 deCONZ::ZclFCManufacturerSpecific |
                                 deCONZ::ZclFCDirectionClientToServer |
                                 deCONZ::ZclFCDisableDefaultResponse);
        zclFrame.setManufacturerCode(manufacturerCode);
    }
    else
    {
        zclFrame.setFrameControl(deCONZ::ZclFCProfileCommand |
                                 deCONZ::ZclFCDirectionClientToServer |
                                 deCONZ::ZclFCDisableDefaultResponse);
    }

    { // payload
        deCONZ::ZclAttribute attribute(attributeId, dataType, QLatin1String(""), deCONZ::ZclReadWrite, true);

        if (expr == QLatin1String("$raw"))
        {
            attribute.setValue(item->toVariant());
        }
        else if (expr.contains(QLatin1String("$raw")) && dataType < deCONZ::ZclOctedString) // numeric data type
        {
            if ((dataType >= deCONZ::Zcl8BitData && dataType <= deCONZ::Zcl64BitUint)
                    || dataType == deCONZ::Zcl8BitEnum || dataType == deCONZ::Zcl16BitEnum)
            {
                expr.replace("$raw", QString::number(item->toNumber()));
            }
            else if (dataType >= deCONZ::Zcl8BitInt && dataType <= deCONZ::Zcl64BitInt)
            {
                expr.replace("$raw", QString::number(item->toNumber()));
            }
            else if (dataType >= deCONZ::ZclSemiFloat && dataType <= deCONZ::ZclDoubleFloat)
            {
                Q_ASSERT(0); // TODO implement
            }
            else
            {
                return result;
            }

            QJSEngine engine;

            const auto res = engine.evaluate(expr);

            if (!res.isError())
            {
                DBG_Printf(DBG_INFO, "expression: %s = %.0f\n", qPrintable(expr), res.toNumber());
                attribute.setValue(res.toVariant());
            }
            else
            {
                DBG_Printf(DBG_INFO, "failed to evaluate expression: %s, err: %d\n", qPrintable(expr), res.errorType());
                return result;
            }
        }

        QDataStream stream(&zclFrame.payload(), QIODevice::WriteOnly);
        stream.setByteOrder(QDataStream::LittleEndian);

        stream << attribute.id();
        stream << attribute.dataType();

        if (!attribute.writeToStream(stream))
        {
            return result;
        }
    }

    { // ZCL frame
        QDataStream stream(&req.asdu(), QIODevice::WriteOnly);
        stream.setByteOrder(QDataStream::LittleEndian);
        zclFrame.writeToStream(stream);
    }

    result = apsCtrl->apsdeDataRequest(req) == deCONZ::Success;

    return result;
}

const std::vector<ParseFunction> parseFunctions = {
    ParseFunction("parseGenericAttribute/4", 4, parseGenericAttribute4)
};

const std::vector<ReadFunction> readFunctions = {
    ReadFunction("readGenericAttribute/4", 4, readGenericAttribute4)
};

const std::vector<WriteFunction> writeFunctions = {
    WriteFunction("writeGenericAttribute/6", 6, writeGenericAttribute6)
};

void initResourceDescriptors()
{
    rPrefixes.clear();
    rItemDescriptors.clear();

    // init resource lookup
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RAttrName));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RAttrManufacturerName));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RAttrModelId));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RAttrType));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RAttrClass));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RAttrId));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RAttrUniqueId));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RAttrProductId));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RAttrSwVersion));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeTime, RAttrLastAnnounced));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeTime, RAttrLastSeen));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt64, RAttrExtAddress));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RAttrNwkAddress));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RAttrGroupAddress));

    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RStateAirQuality));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RStateAirQualityPpb));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RStateAlarm));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RStateAlert));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RStateAllOn));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RStateAngle));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RStateAnyOn));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RStateBattery, 0, 100));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RStateBri));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeInt32, RStateButtonEvent));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RStateCarbonMonoxide));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RStateColorMode));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt64, RStateConsumption));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RStateCurrent));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RStateCt));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RStateDark));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RStateDaylight));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RStateEffect));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RStateErrorCode));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RStateEventDuration));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RStateFire));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RStateFlag));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeInt16, RStateFloorTemperature, -27315, 32767));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeInt32, RStateGesture));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RStateHeating));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RStateHue));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RStateHumidity, 0, 10000));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeTime, RStateLastCheckin));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeTime, RStateLastSet));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeTime, RStateLastUpdated));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RStateLift, 0, 100));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RStateLightLevel, 0, 0xfffe));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeTime, RStateLocaltime));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RStateLowBattery));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt32, RStateLux));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RStateMountingModeActive));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RStateOn));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RStateOpen));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeInt16, RStateOrientationX));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeInt16, RStateOrientationY));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeInt16, RStateOrientationZ));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RStatePresence));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeInt16, RStatePressure, 0, 32767));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeInt16, RStatePower));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RStateReachable));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RStateSat));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RActionScene));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RStateSpectralX));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RStateSpectralY));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RStateSpectralZ));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RStateSpeed, 0, 6));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeInt32, RStateStatus));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeTime, RStateSunrise));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeTime, RStateSunset));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RStateTampered));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeInt16, RStateTemperature, -27315, 32767));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RStateTest));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RStateTilt, 0, 100));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RStateTiltAngle));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeTime, RStateUtc));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RStateValve));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RStateVibration));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RStateVibrationStrength));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RStateVoltage));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RStateWater));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RStateWindowOpen));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RStateX));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RStateY));

    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RConfigAlert));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RConfigBattery, 0, 100));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RConfigColorCapabilities));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RConfigCtMin));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RConfigCtMax));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt32, RConfigCheckin));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RConfigConfigured));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeInt16, RConfigCoolSetpoint, 700, 3500));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RConfigDelay));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RConfigDeviceMode));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RConfigDisplayFlipped));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RConfigDuration));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt32, RConfigEnrolled));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RConfigFanMode));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RConfigGroup));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeInt16, RConfigHeatSetpoint, 500, 3200));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt32, RConfigHostFlags));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt32, RConfigId));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeInt16, RConfigLastChangeAmount));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RConfigLastChangeSource));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeTime, RConfigLastChangeTime));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RConfigLat));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RConfigLedIndication));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeTime, RConfigLocalTime));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RConfigLocked));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RConfigSetValve));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RConfigLong));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RConfigLevelMin));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RConfigMode));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RConfigMountingMode));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeInt16, RConfigOffset, INT16_MIN, INT16_MAX));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RConfigOn));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RConfigPending));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt32, RConfigPowerup));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RConfigPowerOnLevel));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RConfigPowerOnCt));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RConfigPreset));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RConfigMelody));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RConfigVolume));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RConfigTempThreshold));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RConfigHumiThreshold));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RConfigReachable));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RConfigSchedule));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RConfigScheduleOn));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RConfigSensitivity));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RConfigSensitivityMax));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeInt8, RConfigSunriseOffset, -120, 120));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeInt8, RConfigSunsetOffset, -120, 120));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RConfigSwingMode));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeInt16, RConfigTemperature, -27315, 32767));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RConfigTemperatureMeasurement));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RConfigTholdDark, 0, 0xfffe));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RConfigTholdOffset, 1, 0xfffe));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeString, RConfigUrl));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RConfigUsertest));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RConfigWindowCoveringType));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RConfigWindowOpen));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeInt16, RConfigExternalTemperatureSensor));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeBool, RConfigExternalWindowOpen));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RConfigUbisysJ1Mode));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RConfigUbisysJ1WindowCoveringType));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RConfigUbisysJ1ConfigurationAndStatus));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RConfigUbisysJ1InstalledOpenLimitLift));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RConfigUbisysJ1InstalledClosedLimitLift));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RConfigUbisysJ1InstalledOpenLimitTilt));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RConfigUbisysJ1InstalledClosedLimitTilt));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RConfigUbisysJ1TurnaroundGuardTime));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RConfigUbisysJ1LiftToTiltTransitionSteps));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RConfigUbisysJ1TotalSteps));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RConfigUbisysJ1LiftToTiltTransitionSteps2));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RConfigUbisysJ1TotalSteps2));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt8, RConfigUbisysJ1AdditionalSteps));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RConfigUbisysJ1InactivePowerThreshold));
    rItemDescriptors.emplace_back(ResourceItemDescriptor(DataTypeUInt16, RConfigUbisysJ1StartupSteps));
}

const char *getResourcePrefix(const QString &str)
{
    Q_UNUSED(str);
    return nullptr;
}

bool getResourceItemDescriptor(const QString &str, ResourceItemDescriptor &descr)
{
    std::vector<ResourceItemDescriptor>::const_iterator i = rItemDescriptors.begin();
    std::vector<ResourceItemDescriptor>::const_iterator end = rItemDescriptors.end();

    for (; i != end; ++i)
    {
        if (str.endsWith(QLatin1String(i->suffix)))
        {
            descr = *i;
            return true;
        }
    }

    return false;
}

/*! Clears \p flags in \p item which must be a numeric value item.
    The macro is used to print the flag defines as human readable.
 */
bool R_ClearFlags1(ResourceItem *item, qint64 flags, const char *strFlags)
{
    DBG_Assert(item);

    if (item)
    {
        const auto old = item->toNumber();
        if ((old & flags) != 0)
        {
            DBG_Printf(DBG_INFO_L2, "[INFO_L2] - Clear %s flags %s (0x%016llX) in 0x%016llX  --> 0x%016llX\n",
                       item->descriptor().suffix, strFlags, flags, item->toNumber(), old & ~flags);
            item->setValue(item->toNumber() & ~flags);
            return true;
        }
    }
    return false;
}

/*! Sets \p flags in \p item which must be a numeric value item.
    The macro is used to print the flag defines as human readable.
 */
bool R_SetFlags1(ResourceItem *item, qint64 flags, const char *strFlags)
{
    DBG_Assert(item);

    if (item)
    {
        const auto old = item->toNumber();
        if ((old & flags) != flags)
        {
            DBG_Printf(DBG_INFO_L2, "[INFO_L2] - Set %s flags %s (0x%016llX) in 0x%016llX --> 0x%016llX\n",
                       item->descriptor().suffix, strFlags, flags, item->toNumber(), old | flags);
            item->setValue(item->toNumber() | flags);
            return true;
        }
    }

    return false;
}

bool R_HasFlags(const ResourceItem *item, qint64 flags)
{
    DBG_Assert(item);

    if (item)
    {
        return (item->toNumber() & flags) == flags;
    }

    return false;
}

/*! The product map is a helper to map Basic Cluster manufacturer name and modelid
   to human readable product identifiers like marketing string or the model no. as printed on the product package.

   In case of Tuya multiple entries may refer to the same device, so in matching code
   it's best to match against the \c productId.

   Example:

   if (R_GetProductId(sensor) == QLatin1String("SEA801-ZIGBEE TRV"))
   {
   }

   Note: this will later on be replaced with the data from DDF files.
*/
struct ProductMap
{
    const char *zmanufacturerName;
    const char *zmodelId;
    const char *manufacturer;
    // a common product identifier even if multipe branded versions exist
    const char *commonProductId;
};

static const ProductMap products[] =
{
    // Prefix signification
    // --------------------
    // Tuya_THD : thermostat device using Tuya cluster
    // Tuya_COVD : covering device using Tuya cluster


    // Tuya Thermostat / TRV
    {"_TYST11_zuhszj9s", "uhszj9s", "HiHome", "Tuya_THD WZB-TRVL TRV"},
    {"_TYST11_KGbxAXL2", "GbxAXL2", "Saswell", "Tuya_THD SEA801-ZIGBEE TRV"},
    {"_TYST11_c88teujp", "88teujp", "Saswell", "Tuya_THD SEA801-ZIGBEE TRV"},
    {"_TZE200_c88teujp", "TS0601", "Saswell", "Tuya_THD SEA801-ZIGBEE TRV"},
    {"_TYST11_ckud7u2l", "kud7u2l", "Tuya", "Tuya_THD HY369 TRV"},
    {"_TZE200_ckud7u2l", "TS0601", "Tuya", "Tuya_THD HY369 TRV"},
    {"_TZE200_ywdxldoj", "TS0601", "MOES/tuya", "Tuya_THD HY368 TRV"},
    {"_TZE200_aoclfnxz", "TS0601", "Moes", "Tuya_THD BTH-002 Thermostat"},
    {"_TYST11_jeaxp72v", "eaxp72v", "Essentials", "Tuya_THD Essentials TRV"},
    {"_TYST11_kfvq6avy", "fvq6avy", "Revolt", "Tuya_THD NX-4911-675 TRV"},
    {"_TZE200_kfvq6avy", "TS0601", "Revolt", "Tuya_THD NX-4911-675 TRV"},
    {"_TYST11_zivfvd7h", "ivfvd7h", "Siterwell", "Tuya_THD GS361A-H04 TRV"},
    {"_TZE200_zivfvd7h", "TS0601", "Siterwell", "Tuya_THD GS361A-H04 TRV"},
    {"_TYST11_yw7cahqs", "w7cahqs", "Hama", "Tuya_THD Smart radiator TRV"},

    // Tuya Covering
    {"_TYST11_wmcdj3aq", "mcdj3aq", "Zemismart", "Tuya_COVD ZM25TQ"},
    {"_TZE200_wmcdj3aq", "TS0601", "Zemismart", "Tuya_COVD ZM25TQ"},
    {"_TZE200_fzo2pocs", "TS0601", "Zemismart", "Tuya_COVD ZM25TQ"},
    {"_TYST11_xu1rkty3", "u1rkty3", "Smart Home", "Tuya_COVD DT82LEMA-1.2N"},
    {"_TZE200_xuzcvlku", "TS0601", "Zemismart", "Tuya_COVD M515EGB"},
    {"_TZE200_zah67ekd", "TS0601", "MoesHouse / Livolo", "Tuya_COVD AM43-0.45-40"},
    {"_TZE200_nogaemzt", "TS0601", "Tuya", "Tuya_COVD YS-MT750"},
    {"_TZE200_zpzndjez", "TS0601", "Tuya", "Tuya_COVD DS82"},
    {"_TZE200_cowvfni3", "TS0601", "Zemismart", "Tuya_COVD ZM79E-DT"},
    {"_TZE200_5zbp6j0u", "TS0601", "Tuya/Zemismart", "Tuya_COVD DT82LEMA-1.2N"},
    {"_TZE200_fdtjuw7u", "TS0601", "Yushun", "Tuya_COVD YS-MT750"},
    {"_TZE200_bqcqqjpb", "TS0601", "Yushun", "Tuya_COVD YS-MT750"},

    // Tuya covering not using tuya cluster but need reversing
    {"_TZ3000_egq7y6pr", "TS130F", "Lonsonho", "11830304 Switch"},
    {"_TZ3000_xzqbrqk1", "TS130F", "Lonsonho", "Zigbee curtain switch"}, // https://github.com/dresden-elektronik/deconz-rest-plugin/issues/3757#issuecomment-776201454
    {"_TZ3000_ltiqubue", "TS130F", "Tuya", "Zigbee curtain switch"},
    {"_TZ3000_vd43bbfq", "TS130F", "Tuya", "QS-Zigbee-C01 Module"}, // Curtain module QS-Zigbee-C01

    // Other
    {"_TYST11_d0yu2xgi", "0yu2xgi", "NEO/Tuya", "NAS-AB02B0 Siren"},
    {"_TZE200_d0yu2xgi", "TS0601", "NEO/Tuya", "NAS-AB02B0 Siren"},

    {nullptr, nullptr, nullptr, nullptr}
};

/*! Returns the product identifier for a matching Basic Cluster manufacturer name. */
static QLatin1String productIdForManufacturerName(const QString &manufacturerName, const ProductMap *mapIter)
{
    Q_ASSERT(mapIter);

    for (; mapIter->commonProductId != nullptr; mapIter++)
    {
        if (manufacturerName == QLatin1String(mapIter->zmanufacturerName))
        {
            return QLatin1String(mapIter->commonProductId);
        }
    }

    return QLatin1String("");
}

/*! Returns the product identifier for a resource. */
const QString R_GetProductId(Resource *resource)
{
    DBG_Assert(resource);


    if (!resource)
    {
        return rInvalidString;
    }

    auto *productId = resource->item(RAttrProductId);

    if (productId)
    {
        return productId->toString();
    }

    const auto *manufacturerName = resource->item(RAttrManufacturerName);
    const auto *modelId = resource->item(RAttrManufacturerName);

    if (!manufacturerName || !modelId)
    {
        return rInvalidString;
    }

    if (isTuyaManufacturerName(manufacturerName->toString()))
    {
        // for Tuya devices match against manufacturer name
        const auto productIdStr = productIdForManufacturerName(manufacturerName->toString(), products);
        if (productIdStr.size() > 0)
        {
            productId = resource->addItem(DataTypeString, RAttrProductId);
            DBG_Assert(productId);
            productId->setValue(QString(productIdStr));
            productId->setIsPublic(false); // not ready for public
            return productId->toString();
        }
        else
        {
            // Fallback
            // manufacturer name is the most unique identifier for Tuya
            if (DBG_IsEnabled(DBG_INFO_L2))
            {
                DBG_Printf(DBG_INFO_L2, "No Tuya productId entry found for manufacturername: %s, modelId: %s\n",
                    qPrintable(manufacturerName->toString()), qPrintable(modelId->toString()));
            }

            return manufacturerName->toString();
        }
    }
    else
    {
        return modelId->toString();
    }

    return rInvalidString;
}

/*! Copy constructor. */
ResourceItem::ResourceItem(const ResourceItem &other)
{
    *this = other;
}

/*! Move constructor. */
ResourceItem::ResourceItem(ResourceItem &&other) :
    m_isPublic(other.m_isPublic),
    m_flags(other.m_flags),
    m_num(other.m_num),
    m_numPrev(other.m_numPrev),
    m_str(nullptr),
    m_rid(other.m_rid),
    m_lastSet(std::move(other.m_lastSet)),
    m_lastChanged(std::move(other.m_lastChanged)),
    m_rulesInvolved(std::move(other.m_rulesInvolved)),
    m_clusterId(other.m_clusterId),
    m_attributeId(other.m_attributeId),
    m_endpoint(other.m_endpoint),
    m_parseFunction(other.m_parseFunction),
    m_parseParameters(std::move(other.m_parseParameters)),
    m_readParameters(std::move(other.m_readParameters)),
    m_writeParameters(std::move(other.m_writeParameters))

{
    if (other.m_str) // release
    {
        m_str = other.m_str;
        other.m_str = nullptr;
    }

    other.m_rid = &rInvalidItemDescriptor;
}

/*! Destructor. */
ResourceItem::~ResourceItem()
{
    if (m_str)
    {
        delete m_str;
        m_str = nullptr;
    }
}

/*! Returns true when a value has been set but not pushed upstream. */
bool ResourceItem::needPushSet() const
{
    return (m_flags & FlagNeedPushSet) > 0;
}

/*! Returns true when a value has been set and is different from previous
    but not pushed upstream.
 */
bool ResourceItem::needPushChange() const
{
    return (m_flags & FlagNeedPushChange) > 0;
}

/*! Clears set and changed push flags, called after value has been pushed to upstream. */
void ResourceItem::clearNeedPush()
{
    m_flags &= ~static_cast<quint16>(FlagNeedPushSet | FlagNeedPushChange);
}

/*! Copy assignment. */
ResourceItem &ResourceItem::operator=(const ResourceItem &other)
{
    // self assignment?
    if (this == &other)
    {
        return *this;
    }

    m_valueSource = other.m_valueSource;
    m_isPublic = other.m_isPublic;
    m_flags = other.m_flags;
    m_parseFunction = other.m_parseFunction;
    m_parseParameters = other.m_parseParameters;
    m_readParameters = other.m_readParameters;
    m_writeParameters = other.m_writeParameters;
    m_clusterId = other.m_clusterId;
    m_attributeId = other.m_attributeId;
    m_endpoint = other.m_endpoint;
    m_num = other.m_num;
    m_numPrev = other.m_numPrev;
    m_rid = other.m_rid;
    m_lastSet = other.m_lastSet;
    m_lastChanged = other.m_lastChanged;
    m_rulesInvolved = other.m_rulesInvolved;

    if (other.m_str)
    {
        if (m_str)
        {
            *m_str = *other.m_str;
        }
        else
        {
            m_str = new QString(*other.m_str);
        }
    }
    else if (m_str)
    {
        delete m_str;
        m_str = nullptr;
    }

    return *this;
}

/*! Move assignment. */
ResourceItem &ResourceItem::operator=(ResourceItem &&other)
{
    // self assignment?
    if (this == &other)
    {
        return *this;
    }

    m_valueSource = other.m_valueSource;
    m_isPublic = other.m_isPublic;
    m_flags = other.m_flags;
    m_num = other.m_num;
    m_numPrev = other.m_numPrev;
    m_rid = other.m_rid;
    m_lastSet = std::move(other.m_lastChanged);
    m_lastChanged = std::move(other.m_lastChanged);
    m_rulesInvolved = std::move(other.m_rulesInvolved);
    m_clusterId = other.m_clusterId;
    m_attributeId = other.m_attributeId;
    m_endpoint = other.m_endpoint;
    m_parseFunction = other.m_parseFunction;
    m_parseParameters = std::move(other.m_parseParameters);
    m_readParameters = std::move(other.m_readParameters);
    m_writeParameters = std::move(other.m_writeParameters);
    other.m_rid = &rInvalidItemDescriptor;

    if (m_str)
    {
        delete m_str;
        m_str = nullptr;
    }

    if (other.m_str)
    {
        m_str = other.m_str;
        other.m_str = nullptr;
    }

    return *this;
}

/*! Initial main constructor to create a valid ResourceItem. */
ResourceItem::ResourceItem(const ResourceItemDescriptor &rid) :
    m_num(0),
    m_numPrev(0),
    m_str(nullptr),
    m_rid(&rid)
{
    if (m_rid->type == DataTypeString ||
        m_rid->type == DataTypeTime ||
        m_rid->type == DataTypeTimePattern)
    {
        m_str = new QString;
    }

    if (rid.suffix == RAttrModelId)
    {
        // basic cluster, model identifier
//        setParseParameters({"parseGenericAttribute/4", 0xff, 0x0000, 0x0005, "$raw" });
    }
    else if (rid.suffix == RAttrManufacturerName)
    {
        // basic cluster, manufacturer name
//        setParseParameters({"parseGenericAttribute/4", 0xff, 0x0000, 0x0004, "$raw" });
    }
}

const QString &ResourceItem::toString() const
{
    if (m_rid->type == DataTypeString ||
        m_rid->type == DataTypeTimePattern)
    {
        if (m_str)
        {
            return *m_str;
        }
    }
    else if (m_rid->type == DataTypeTime)
    {
        if (m_num > 0)
        {
            QDateTime dt;

            // default: local time in sec resolution
            QString format = QLatin1String("yyyy-MM-ddTHH:mm:ss");

            if (m_rid->suffix == RStateLastUpdated || m_rid->suffix == RStateLastCheckin)
            {
                // UTC in msec resolution
                format = QLatin1String("yyyy-MM-ddTHH:mm:ss.zzz"); // TODO add Z
                dt.setOffsetFromUtc(0);
            }
            else if (m_rid->suffix == RAttrLastAnnounced || m_rid->suffix == RStateLastSet || m_rid->suffix == RStateUtc || m_rid->suffix == RConfigLastChangeTime)
            {
                // UTC in sec resolution
                format = QLatin1String("yyyy-MM-ddTHH:mm:ssZ");
                dt.setOffsetFromUtc(0);
            }
            else if (m_rid->suffix == RAttrLastSeen)
            {
                // UTC in min resolution
                format = QLatin1String("yyyy-MM-ddTHH:mmZ");
                dt.setOffsetFromUtc(0);
            }
            else if (m_rid->suffix == RStateSunrise || m_rid->suffix == RStateSunset)
            {
                // UTC in sec resulution
                format = QLatin1String("yyyy-MM-ddTHH:mm:ss"); // TODO add Z
                dt.setOffsetFromUtc(0);
            }

            dt.setMSecsSinceEpoch(m_num);
            *m_str = dt.toString(format);
            return *m_str;
        }
    }

    return rInvalidString;
}

qint64 ResourceItem::toNumber() const
{
    return m_num;
}

qint64 ResourceItem::toNumberPrevious() const
{
    return m_numPrev;
}

bool ResourceItem::toBool() const
{
    return m_num != 0;
}

bool ResourceItem::setValue(const QString &val, ValueSource source)
{
    if (m_str)
    {
        m_valueSource = source;
        m_lastSet = QDateTime::currentDateTime();
        m_flags |= FlagNeedPushSet;
        if (*m_str != val)
        {
            *m_str = val;
            m_lastChanged = m_lastSet;
            m_flags |= FlagNeedPushChange;
        }
        return true;
    }

    return false;
}

bool ResourceItem::setValue(qint64 val, ValueSource source)
{
    if (m_rid->validMin != 0 || m_rid->validMax != 0)
    {
        // range check
        if (val < m_rid->validMin || val > m_rid->validMax)
        {
            return false;
        }
    }

    m_lastSet = QDateTime::currentDateTime();
    m_numPrev = m_num;
    m_valueSource = source;
    m_flags |= FlagNeedPushSet;

    if (m_num != val)
    {
        m_num = val;
        m_lastChanged = m_lastSet;
        m_flags |= FlagNeedPushChange;
    }

    return true;
}

bool ResourceItem::setValue(const QVariant &val, ValueSource source)
{
    if (!val.isValid())
    {
        m_lastSet = QDateTime();
        m_lastChanged = m_lastSet;
        m_valueSource = SourceUnknown;
        return true;
    }

    const auto now = QDateTime::currentDateTime();
    m_valueSource = source;


    if (m_rid->type == DataTypeString ||
        m_rid->type == DataTypeTimePattern)
    {
        // TODO validate time pattern
        if (m_str)
        {
            m_lastSet = now;
            m_flags |= FlagNeedPushSet;
            if (*m_str != val.toString().trimmed())
            {
                *m_str = val.toString().trimmed();
                m_lastChanged = m_lastSet;
                m_flags |= FlagNeedPushChange;
            }
            return true;
        }
    }
    else if (m_rid->type == DataTypeBool)
    {
        m_lastSet = now;
        m_numPrev = m_num;
        m_flags |= FlagNeedPushSet;

        if (m_num != val.toBool())
        {
            m_num = val.toBool();
            m_lastChanged = m_lastSet;
            m_flags |= FlagNeedPushChange;
        }
        return true;
    }
    else if (m_rid->type == DataTypeTime)
    {
        if (val.type() == QVariant::String)
        {
            QDateTime dt = QDateTime::fromString(val.toString(), QLatin1String("yyyy-MM-ddTHH:mm:ss"));

            if (dt.isValid())
            {
                m_lastSet = now;
                m_numPrev = m_num;
                m_flags |= FlagNeedPushSet;

                if (m_num != dt.toMSecsSinceEpoch())
                {
                    m_num = dt.toMSecsSinceEpoch();
                    m_lastChanged = m_lastSet;
                    m_flags |= FlagNeedPushChange;
                }
                return true;
            }
        }
        else if (val.type() == QVariant::DateTime)
        {
            m_lastSet = now;
            m_numPrev = m_num;
            m_flags |= FlagNeedPushSet;

            if (m_num != val.toDateTime().toMSecsSinceEpoch())
            {
                m_num = val.toDateTime().toMSecsSinceEpoch();
                m_lastChanged = m_lastSet;
                m_flags |= FlagNeedPushChange;
            }
            return true;
        }
    }
    else
    {
        if (m_rid->type == DataTypeReal)
        {
            DBG_Printf(DBG_ERROR, "todo handle DataTypeReal in %s", __FUNCTION__);
        }

        bool ok = false;
        const int n = val.toInt(&ok);

        if (ok)
        {
            if (m_rid->validMin == 0 && m_rid->validMax == 0)
            { /* no range check */ }
            else if (n >= m_rid->validMin && n <= m_rid->validMax)
            {   /* range check: ok*/ }
            else {
                m_valueSource = SourceUnknown;
                return false;
            }

            m_lastSet = now;
            m_numPrev = m_num;
            m_flags |= FlagNeedPushSet;

            if (m_num != n)
            {
                m_num = n;
                m_lastChanged = m_lastSet;
                m_flags |= FlagNeedPushChange;
            }
            return true;
        }
    }

    m_valueSource = SourceUnknown;
    return false;
}

const ResourceItemDescriptor &ResourceItem::descriptor() const
{
    Q_ASSERT(m_rid);
    return *m_rid;
}

const QDateTime &ResourceItem::lastSet() const
{
    return m_lastSet;
}

const QDateTime &ResourceItem::lastChanged() const
{
    return m_lastChanged;
}

void ResourceItem::setTimeStamps(const QDateTime &t)
{
    m_lastSet = t;
    m_lastChanged = t;
}

QVariant ResourceItem::toVariant() const
{
    if (!m_lastSet.isValid())
    {
        return QVariant();
    }

    if (m_rid->type == DataTypeString ||
        m_rid->type == DataTypeTimePattern)
    {
        if (m_str)
        {
            return *m_str;
        }
        return QString();
    }
    else if (m_rid->type == DataTypeBool)
    {
        return (bool)m_num;
    }
    else if (m_rid->type == DataTypeTime)
    {
        return toString();
    }
    else
    {
       return (double)m_num;
    }

    return QVariant();
}

void ResourceItem::setZclProperties(quint16 clusterId, quint16 attrId, quint8 endpoint)
{
    m_clusterId = clusterId;
    m_attributeId = attrId;
    m_endpoint = endpoint;
}

/*! Marks the resource item as involved in a rule. */
void ResourceItem::inRule(int ruleHandle)
{
    for (int handle : m_rulesInvolved)
    {
        if (handle == ruleHandle)
        {
            return;
        }
    }

    m_rulesInvolved.push_back(ruleHandle);
}

/*! Returns the rules handles in which the resource item is involved. */
const std::vector<int> ResourceItem::rulesInvolved() const
{
    return m_rulesInvolved;
}

/*! Returns true if the item should be available in the public api. */
bool ResourceItem::isPublic() const
{
    return m_isPublic;
}

/*! Sets an item should be available in the public api. */
void ResourceItem::setIsPublic(bool isPublic)
{
    m_isPublic = isPublic;
}

void ResourceItem::setParseParameters(const std::vector<QVariant> &params)
{
    m_parseParameters = params;
}

void ResourceItem::setReadParameters(const std::vector<QVariant> &params)
{
    m_readParameters = params;
}

void ResourceItem::setWriteParameters(const std::vector<QVariant> &params)
{
    m_writeParameters = params;
}

/*! Initial main constructor. */
Resource::Resource(const char *prefix) :
    m_prefix(prefix)
{
    Q_ASSERT(prefix == RSensors || prefix == RLights || prefix == RGroups || prefix == RConfig || prefix == RDevices);
}

/*! Copy constructor. */
Resource::Resource(const Resource &other) :
    lastStatePush(other.lastStatePush),
    lastAttrPush(other.lastAttrPush),
    m_prefix(other.m_prefix),
    m_parent(other.m_parent),
    m_rItems(other.m_rItems)
{
}

/*! Move constructor. */
Resource::Resource(Resource &&other) :
    lastStatePush(std::move(other.lastStatePush)),
    lastAttrPush(std::move(other.lastAttrPush)),
    m_prefix(other.m_prefix),
    m_parent(other.m_parent),
    m_rItems(std::move(other.m_rItems))
{
    other.m_prefix = RInvalidSuffix;
}

/*! Copy assignment. */
Resource &Resource::operator=(const Resource &other)
{
    if (this != &other)
    {
        lastStatePush = other.lastStatePush;
        lastAttrPush = other.lastAttrPush;
        m_prefix = other.m_prefix;
        m_parent = other.m_parent;
        m_rItems = other.m_rItems;
    }
    return *this;
}

/*! Move assignment. */
Resource &Resource::operator=(Resource &&other)
{
    if (this != &other)
    {
        lastStatePush = std::move(other.lastStatePush);
        lastAttrPush = std::move(other.lastAttrPush);
        m_prefix = other.m_prefix;
        m_parent = other.m_parent;
        m_rItems = std::move(other.m_rItems);
    }
    return *this;
}

const char *Resource::prefix() const
{
    Q_ASSERT(m_prefix);
    return m_prefix;
}

ResourceItem *Resource::addItem(ApiDataType type, const char *suffix)
{
    ResourceItem *it = item(suffix);
    if (!it) // prevent double insertion
    {
        std::vector<ResourceItemDescriptor>::const_iterator i = rItemDescriptors.begin();
        std::vector<ResourceItemDescriptor>::const_iterator end = rItemDescriptors.end();

        for (; i != end; ++i)
        {
            if (i->suffix == suffix && i->type == type)
            {
                m_rItems.emplace_back(*i);
                return &m_rItems.back();
            }
        }

        DBG_Assert(0);
        DBG_Printf(DBG_ERROR, "unknown datatype:suffix +  %d: %s\n", type, suffix);
    }

    return it;
}

void Resource::removeItem(const char *suffix)
{
    auto i = m_rItems.begin();
    const auto end = m_rItems.end();

    for (; i != end; ++i)
    {
        if (i->descriptor().suffix != suffix)
        {
            continue;
        }

        *i = std::move(m_rItems.back());
        m_rItems.pop_back();
        break;
    }
}

ResourceItem *Resource::item(const char *suffix)
{
    for (size_t i = 0; i < m_rItems.size(); i++)
    {
        if (m_rItems[i].descriptor().suffix == suffix)
        {
            return &m_rItems[i];
        }
    }

    return nullptr;
}

const ResourceItem *Resource::item(const char *suffix) const
{
    for (size_t i = 0; i < m_rItems.size(); i++)
    {
        if (m_rItems[i].descriptor().suffix == suffix)
        {
            return &m_rItems[i];
        }
    }

    return nullptr;
}

bool Resource::toBool(const char *suffix) const
{
    const ResourceItem *i = item(suffix);
    if (i)
    {
        return i->toBool();
    }
    return false;
}

qint64 Resource::toNumber(const char *suffix) const
{
    const ResourceItem *i = item(suffix);
    if (i)
    {
        return i->toNumber();
    }
    return 0;
}

const QString &Resource::toString(const char *suffix) const
{
    const ResourceItem *i = item(suffix);
    if (i)
    {
        return i->toString();
    }
    return rInvalidString;
}

QVariant Resource::toVariant(const char *suffix) const
{
    const ResourceItem *i = item(suffix);
    if (i)
    {
        return i->toVariant();
    }
    return QVariant();
}

int Resource::itemCount() const
{
    return m_rItems.size();
}

ResourceItem *Resource::itemForIndex(size_t idx)
{
    if (idx < m_rItems.size())
    {
        return &m_rItems[idx];
    }
    return nullptr;
}

const ResourceItem *Resource::itemForIndex(size_t idx) const
{
    if (idx < m_rItems.size())
    {
        return &m_rItems[idx];
    }
    return nullptr;
}

/*! Adds \p stateChange to a Resource.

    If an equal StateChange already exists it will be replaced.
 */
void Resource::addStateChange(const StateChange &stateChange)
{
    auto i = std::find(m_stateChanges.begin(), m_stateChanges.end(), stateChange);

    if (i != m_stateChanges.end())
    {
        *i = stateChange;
    }
    else
    {
        m_stateChanges.push_back(stateChange);
    }
}

/*! Removes all StateChange items having state StateFailed or StateFinished. */
void Resource::cleanupStateChanges()
{
    while (!m_stateChanges.empty())
    {
        const auto i = std::find_if(m_stateChanges.begin(), m_stateChanges.end(), [](const StateChange &x)
        {
            return x.state() == StateChange::StateFailed || x.state() == StateChange::StateFinished;
        });

        if (i != m_stateChanges.end())
        {
            if (i->state() == StateChange::StateFinished)
            {
                DBG_Printf(DBG_INFO, "SC state change finished: %s\n", qPrintable(item(RAttrUniqueId)->toString()));
            }
            else if (i->state() == StateChange::StateFailed)
            {
                DBG_Printf(DBG_INFO, "SC state change failed: %s\n", qPrintable(item(RAttrUniqueId)->toString()));
            }

            m_stateChanges.erase(i);
        }
        else
        {
            break;
        }
    }
}

ParseFunction_t getParseFunction(const std::vector<ParseFunction> &functions, const std::vector<QVariant> &params)
{
    ParseFunction_t result = nullptr;

    if (params.size() >= 1)
    {
        const auto fnName = params.at(0).toString();
        for (const auto &pf : functions)
        {
            if (pf.name == fnName)
            {
                result = pf.fn;
                break;
            }
        }
    }

    return result;
}

ReadFunction_t getReadFunction(const std::vector<ReadFunction> &functions, const std::vector<QVariant> &params)
{
    ReadFunction_t result = nullptr;

    if (params.size() >= 1)
    {
        const auto fnName = params.at(0).toString();
        for (const auto &pf : functions)
        {
            if (pf.name == fnName)
            {
                result = pf.fn;
                break;
            }
        }
    }

    return result;
}

WriteFunction_t getWriteFunction(const std::vector<WriteFunction> &functions, const std::vector<QVariant> &params)
{
    WriteFunction_t result = nullptr;

    if (params.size() >= 1)
    {
        const auto fnName = params.at(0).toString();
        for (const auto &pf : functions)
        {
            if (pf.name == fnName)
            {
                result = pf.fn;
                break;
            }
        }
    }

    return result;
}


StateChange::StateChange(StateChange::State initialState, StateChangeFunction_t fn, quint8 dstEndpoint) :
    m_state(initialState),
    m_changeFunction(fn),
    m_dstEndpoint(dstEndpoint)
{
    Q_ASSERT(initialState == StateCallFunction || initialState == StateWaitSync);
    Q_ASSERT(fn);

    m_stateTimer.start();
    m_changeTimer.start();
}

/*! Tick function for the inner state machine.

    Is called from the Device state machine on certain events.
*/
StateChange::State StateChange::tick(Resource *r, deCONZ::ApsController *apsCtrl)
{
    if (m_state == StateFinished || m_state == StateFailed)
    {
        return m_state;
    }

    auto rParent = r->parentResource() ? r->parentResource() : r;
    auto *device = static_cast<Device*>(rParent);

    Q_ASSERT(device);
    Q_ASSERT(rParent);
    Q_ASSERT(m_stateTimer.isValid());
    Q_ASSERT(m_changeTimer.isValid());

    if (m_state == StateWaitSync && device->reachable())
    {
        if (m_stateTimer.elapsed() > m_stateTimeoutMs)
        {
            m_state = StateCallFunction;

            for (auto &i : m_items)
            {
                if (i.verified == VerifyUnknown) // didn't receive a ZCL attribute read or report command
                {
                    DBG_Printf(DBG_INFO, "SC tick --> StateRead\n");
                    m_state = StateRead;
                    break;
                }
            }
        }
    }

    if (m_state == StateFailed)
    {

    }
    else if (m_changeTimeoutMs > 0 && m_changeTimer.elapsed() > m_changeTimeoutMs)
    {
        m_state = StateFailed;
    }
    else if (m_state == StateCallFunction && m_changeFunction)
    {
        DBG_Printf(DBG_INFO, "SC tick --> StateCallFunction\n");
        if (m_changeFunction(r, this, apsCtrl) == 0)
        {
            m_stateTimer.start();
            m_changeCalls++;

            for (auto &i : m_items)
            {
                if (i.verified == VerifyNotSynced)
                {
                    i.verified = VerifyUnknown; // read again
                }
            }
            m_state = StateWaitSync;
        }
    }
    else if (m_state == StateRead)
    {
        ResourceItem *item = nullptr;
        for (auto &i : m_items)
        {
            if (i.verified == VerifyUnknown)
            {
                item = r->item(i.suffix);
                break;
            }
        }

        m_state = StateFailed;
        if (item && !item->readParameters().empty())
        {
            const auto fn = getReadFunction(readFunctions, item->readParameters());
            if (fn && fn(rParent, item, apsCtrl))
            {
                m_stateTimer.start();
                m_state = StateWaitSync;
            }
        }
    }

    return m_state;
}

/*! Should be called when the item was set by a ZCL read or report attribute command.

    When all items are verified the StateChange::state() is set to StateFinished.
 */
void StateChange::verifyItemChange(const ResourceItem *item)
{
    Q_ASSERT(item);

    size_t syncedItems = 0;

    if (item->valueSource() != ResourceItem::SourceDevice)
    {
        return;
    }

    for (auto &i : m_items)
    {
        if (i.suffix == item->descriptor().suffix)
        {
            if (i.targetValue == item->toVariant())
            {
                i.verified = VerifySynced;
                DBG_Printf(DBG_INFO, "SC %s: synced\n", i.suffix);
            }
            else
            {
                i.verified = VerifyNotSynced;
                DBG_Printf(DBG_INFO, "SC %s: not synced\n", i.suffix);
            }
        }

        if (i.verified == VerifySynced)
        {
            syncedItems++;
        }
    }

    if (syncedItems == m_items.size() && m_state != StateFinished)
    {
        m_state = StateFinished;
        DBG_Printf(DBG_INFO, "SC --> StateFinished\n");
    }
}

/*! Adds a target value. */
void StateChange::addTargetValue(const char *suffix, const QVariant &value)
{
    m_items.push_back({suffix, value});
}

/*! Adds a parameter. If the parameter already exsits it will be replaced. */
void StateChange::addParameter(const QString &name, const QVariant &value)
{
    auto i = std::find_if(m_parameters.begin(), m_parameters.end(), [name](const Param &x){
        return x.name == name;
    });

    if (i != m_parameters.end())
    {
        i->value = value;
    }
    else
    {
        m_parameters.push_back({name, value});
    }
}
