//
// Created by rimokh_y on 27/05/2017.
//

#include <stdexcept>
#include <windows.h>
#include <pdhmsg.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <wbemcli.h>
#include <wbemidl.h>
#include "CPUInfo.hpp"

void getErrorFromStatus(PDH_STATUS status) {
    switch (status) {
        case ERROR_SUCCESS:
            return;
        case PDH_CSTATUS_BAD_COUNTERNAME:
            throw std::runtime_error("The counter path could not be parsed or interpreted.");
            break;
        case PDH_CSTATUS_NO_COUNTER:
            throw std::runtime_error("Unable to find the specified counter on the computer or in the log file.");
            break;
        case PDH_CSTATUS_NO_COUNTERNAME:
            throw std::runtime_error("The counter path is empty.");
            break;
        case PDH_CSTATUS_NO_MACHINE:
            throw std::runtime_error("The path did not contain a computer name, and the function was unable to retrieve the local computer name.");
            break;
        case PDH_CSTATUS_NO_OBJECT:
            throw std::runtime_error("Unable to find the specified object on the computer or in the log file. 1");
            break;
        case PDH_FUNCTION_NOT_FOUND:
            throw std::runtime_error("Unable to determine the calculation function to use for this counter.");
            break;
        case PDH_INVALID_ARGUMENT:
            throw std::runtime_error("One or more arguments are not valid.");
            break;
        case PDH_INVALID_HANDLE:
            throw std::runtime_error("The query handle is not valid.");
            break;
        case PDH_MEMORY_ALLOCATION_FAILURE:
            throw std::runtime_error("Unable to allocate memory required to complete the function.");
            break;
        case PDH_NO_DATA:
            throw std::runtime_error("The query does not currently contain any counters. The query may not contain data because the user is not running with an elevated token (see Limited User Access Support).");
            break;
        default:
            throw std::runtime_error("UNKNOWN");
    }
}

CPUInfo::CPUInfo() {
    GetSystemInfo(&_sysinfo);
    getErrorFromStatus(PdhOpenQuery(NULL, 0, &_cpuQuery));
    getErrorFromStatus(PdhAddEnglishCounter(_cpuQuery, "\\Processor(_Total)\\% Processor Time", 0, &_cpuTotal));
    getErrorFromStatus(PdhCollectQueryData(_cpuQuery));

}

CPUInfo::~CPUInfo() {
    PdhCloseQuery(_cpuQuery);
}

unsigned long       CPUInfo::CPUsNumber() {
    return _sysinfo.dwNumberOfProcessors;
}

std::string     CPUInfo::CPUArchitecture() {
    switch (_sysinfo.wProcessorArchitecture) {
        default:
            return "UNKNOWN";
        case PROCESSOR_ARCHITECTURE_INTEL:
            return "PROCESSOR_ARCHITECTURE_INTEL";
        case PROCESSOR_ARCHITECTURE_MIPS:
            return "PROCESSOR_ARCHITECTURE_MIPS";
        case PROCESSOR_ARCHITECTURE_ALPHA:
            return "PROCESSOR_ARCHITECTURE_ALPHA";
        case PROCESSOR_ARCHITECTURE_PPC:
            return "PROCESSOR_ARCHITECTURE_PPC";
        case PROCESSOR_ARCHITECTURE_SHX:
            return "PROCESSOR_ARCHITECTURE_SHX";
        case PROCESSOR_ARCHITECTURE_ARM:
            return "PROCESSOR_ARCHITECTURE_ARM";
        case PROCESSOR_ARCHITECTURE_IA64:
            return "PROCESSOR_ARCHITECTURE_IA64";
        case PROCESSOR_ARCHITECTURE_ALPHA64:
            return "PROCESSOR_ARCHITECTURE_ALPHA64";
        case PROCESSOR_ARCHITECTURE_MSIL:
            return "PROCESSOR_ARCHITECTURE_MSIL";
        case PROCESSOR_ARCHITECTURE_AMD64:
            return "PROCESSOR_ARCHITECTURE_AMD64";
        case PROCESSOR_ARCHITECTURE_IA32_ON_WIN64:
            return "PROCESSOR_ARCHITECTURE_IA32_ON_WIN64";
        case PROCESSOR_ARCHITECTURE_NEUTRAL:
            return "PROCESSOR_ARCHITECTURE_NEUTRAL";
    }
}

std::string     CPUInfo::CPUType() {
    switch (_sysinfo.dwProcessorType) {
        default:
        case PROCESSOR_INTEL_386:
            return "PROCESSOR_INTEL_386";
        case PROCESSOR_INTEL_486:
            return "PROCESSOR_INTEL_486";
        case PROCESSOR_INTEL_PENTIUM:
            return "PROCESSOR_INTEL_PENTIUM";
        case PROCESSOR_INTEL_IA64:
            return "PROCESSOR_INTEL_IA64";
        case PROCESSOR_AMD_X8664:
            return "PROCESSOR_AMD_X8664";
        case PROCESSOR_MIPS_R4000:
            return "PROCESSOR_MIPS_R4000";
        case PROCESSOR_ALPHA_21064:
            return "PROCESSOR_ALPHA_21064";
        case PROCESSOR_PPC_601:
            return "PROCESSOR_PPC_601";
        case PROCESSOR_PPC_603:
            return "PROCESSOR_PPC_603";
        case PROCESSOR_PPC_604:
            return "PROCESSOR_PPC_604";
        case PROCESSOR_PPC_620:
            return "PROCESSOR_PPC_620";
        case PROCESSOR_HITACHI_SH3:
            return "PROCESSOR_HITACHI_SH3";
        case PROCESSOR_HITACHI_SH3E:
            return "PROCESSOR_HITACHI_SH3E";
        case PROCESSOR_HITACHI_SH4:
            return "PROCESSOR_HITACHI_SH4";
        case PROCESSOR_MOTOROLA_821:
            return "PROCESSOR_MOTOROLA_821";
        case PROCESSOR_SHx_SH3:
            return "PROCESSOR_SHx_SH3";
        case PROCESSOR_SHx_SH4:
            return "PROCESSOR_SHx_SH4";
        case PROCESSOR_STRONGARM:
            return "PROCESSOR_STRONGARM";
        case PROCESSOR_ARM720:
            return "PROCESSOR_ARM720";
        case PROCESSOR_ARM820:
            return "PROCESSOR_ARM820";
        case PROCESSOR_ARM920:
            return "PROCESSOR_ARM920";
        case PROCESSOR_ARM_7TDMI:
            return "PROCESSOR_ARM_7TDMI";
        case PROCESSOR_OPTIL:
            return "PROCESSOR_OPTIL";
    }
}

double             CPUInfo::CPUUsage() {
    PDH_FMT_COUNTERVALUE counterVal;

    getErrorFromStatus(PdhCollectQueryData(_cpuQuery));
    getErrorFromStatus(PdhGetFormattedCounterValue(_cpuTotal, PDH_FMT_DOUBLE, NULL, &counterVal));
    return counterVal.doubleValue;
}

__int64             CPUInfo::CPUUsage(std::string const &processName) {
    return 0;
}

double              CPUInfo::CPUMaxSpeed() {
    wchar_t Buffer[_MAX_PATH];
    DWORD BufSize = _MAX_PATH;
    DWORD dwMHz = _MAX_PATH;
    HKEY hKey;

    long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
                               "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
                               0,
                               KEY_READ,
                               &hKey);
    if (lError != ERROR_SUCCESS)
        return 0;
    RegQueryValueEx(hKey, "~MHz", NULL, NULL, (LPBYTE) &dwMHz, &BufSize);
    return (double)dwMHz / 1000;
}

double              CPUInfo::CPUCurrentSpeed() {
    return 0;
}

double              CPUInfo::CPUTemperature() {
    HRESULT ci = CoInitialize(NULL);
    HRESULT hr = CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);
    if (SUCCEEDED(hr))
    {
        IWbemLocator *pLocator;
        hr = CoCreateInstance(CLSID_WbemAdministrativeLocator, NULL, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID*)&pLocator);
        if (SUCCEEDED(hr))
        {
            IWbemServices *pServices;
            BSTR ns = SysAllocString(L"root\\WMI");
            hr = pLocator->ConnectServer(ns, NULL, NULL, NULL, 0, NULL, NULL, &pServices);
            pLocator->Release();
            SysFreeString(ns);
            if (SUCCEEDED(hr))
            {
                BSTR query = SysAllocString(L"SELECT * FROM MSAcpi_ThermalZoneTemperature");
                BSTR wql = SysAllocString(L"WQL");
                IEnumWbemClassObject *pEnum;
                hr = pServices->ExecQuery(wql, query, WBEM_FLAG_RETURN_IMMEDIATELY | WBEM_FLAG_FORWARD_ONLY, NULL, &pEnum);
                SysFreeString(wql);
                SysFreeString(query);
                pServices->Release();
                if (SUCCEEDED(hr))
                {
                    IWbemClassObject *pObject;
                    ULONG returned;
                    hr = pEnum->Next(WBEM_INFINITE, 1, &pObject, &returned);
                    pEnum->Release();
                    if (SUCCEEDED(hr))
                    {
                        BSTR temp = SysAllocString(L"CurrentTemperature");
                        VARIANT v;
                        VariantInit(&v);
                        hr = pObject->Get(temp, 0, &v, NULL, NULL);
                        pObject->Release();
                        SysFreeString(temp);
                        if (SUCCEEDED(hr)) {
                            return ((double)V_I4(&v) / 10 - 273.15);
                        } else {
                            std::cerr << "caca" << std::endl;
                        }
                        VariantClear(&v);
                    }
                }
            }
            if (ci == S_OK)
            {
                CoUninitialize();
            }
        }
    }
    return hr;
//    system("wmic /namespace:\\\\root\\wmi PATH MSAcpi_ThermalZoneTemperature get CurrentTemperature");
    return 0;
}

