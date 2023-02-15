#define CL_USE_DEPRECATED_OPENCL_1_0_APIS
#define CL_TARGET_OPENCL_VERSION 300
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif
#include <JO/jo.h>
#include "jo_utils.h"

int _joZaincjalizowano = 0; // TODO not thread safe
pustka _joInicjalizuj() {
    if (_joZaincjalizowano) return;
    _joZaincjalizowano = 1;
    loadOpenclLibrary();
    if (openclLibrary) {
        INITIALIZE_FUNCTION(clGetPlatformIDs)
        INITIALIZE_FUNCTION(clGetPlatformInfo)
        INITIALIZE_FUNCTION(clGetDeviceIDs)
        INITIALIZE_FUNCTION(clGetDeviceInfo)
        INITIALIZE_FUNCTION(clCreateSubDevices)
        INITIALIZE_FUNCTION(clRetainDevice)
        INITIALIZE_FUNCTION(clReleaseDevice)
        INITIALIZE_FUNCTION(clSetDefaultDeviceCommandQueue)
        INITIALIZE_FUNCTION(clGetDeviceAndHostTimer)
        INITIALIZE_FUNCTION(clGetHostTimer)
        INITIALIZE_FUNCTION(clCreateContext)
        INITIALIZE_FUNCTION(clCreateContextFromType)
        INITIALIZE_FUNCTION(clRetainContext)
        INITIALIZE_FUNCTION(clReleaseContext)
        INITIALIZE_FUNCTION(clGetContextInfo)
        INITIALIZE_FUNCTION(clSetContextDestructorCallback)
        INITIALIZE_FUNCTION(clCreateCommandQueueWithProperties)
        INITIALIZE_FUNCTION(clRetainCommandQueue)
        INITIALIZE_FUNCTION(clReleaseCommandQueue)
        INITIALIZE_FUNCTION(clGetCommandQueueInfo)
        INITIALIZE_FUNCTION(clCreateBuffer)
        INITIALIZE_FUNCTION(clCreateSubBuffer)
        INITIALIZE_FUNCTION(clCreateImage)
        INITIALIZE_FUNCTION(clCreatePipe)
        INITIALIZE_FUNCTION(clCreateBufferWithProperties)
        INITIALIZE_FUNCTION(clCreateImageWithProperties)
        INITIALIZE_FUNCTION(clRetainMemObject)
        INITIALIZE_FUNCTION(clReleaseMemObject)
        INITIALIZE_FUNCTION(clGetSupportedImageFormats)
        INITIALIZE_FUNCTION(clGetMemObjectInfo)
        INITIALIZE_FUNCTION(clGetImageInfo)
        INITIALIZE_FUNCTION(clGetPipeInfo)
        INITIALIZE_FUNCTION(clSetMemObjectDestructorCallback)
        INITIALIZE_FUNCTION(clSVMAlloc)
        INITIALIZE_FUNCTION(clSVMFree)
        INITIALIZE_FUNCTION(clCreateSamplerWithProperties)
        INITIALIZE_FUNCTION(clRetainSampler)
        INITIALIZE_FUNCTION(clReleaseSampler)
        INITIALIZE_FUNCTION(clGetSamplerInfo)
        INITIALIZE_FUNCTION(clCreateProgramWithSource)
        INITIALIZE_FUNCTION(clCreateProgramWithBinary)
        INITIALIZE_FUNCTION(clCreateProgramWithBuiltInKernels)
        INITIALIZE_FUNCTION(clCreateProgramWithIL)
        INITIALIZE_FUNCTION(clRetainProgram)
        INITIALIZE_FUNCTION(clReleaseProgram)
        INITIALIZE_FUNCTION(clBuildProgram)
        INITIALIZE_FUNCTION(clCompileProgram)
        INITIALIZE_FUNCTION(clLinkProgram)
        INITIALIZE_FUNCTION(clSetProgramReleaseCallback)
        INITIALIZE_FUNCTION(clSetProgramSpecializationConstant)
        INITIALIZE_FUNCTION(clUnloadPlatformCompiler)
        INITIALIZE_FUNCTION(clGetProgramInfo)
        INITIALIZE_FUNCTION(clGetProgramBuildInfo)
        INITIALIZE_FUNCTION(clCreateKernel)
        INITIALIZE_FUNCTION(clCreateKernelsInProgram)
        INITIALIZE_FUNCTION(clCloneKernel)
        INITIALIZE_FUNCTION(clRetainKernel)
        INITIALIZE_FUNCTION(clReleaseKernel)
        INITIALIZE_FUNCTION(clSetKernelArg)
        INITIALIZE_FUNCTION(clSetKernelArgSVMPointer)
        INITIALIZE_FUNCTION(clSetKernelExecInfo)
        INITIALIZE_FUNCTION(clGetKernelInfo)
        INITIALIZE_FUNCTION(clGetKernelArgInfo)
        INITIALIZE_FUNCTION(clGetKernelWorkGroupInfo)
        INITIALIZE_FUNCTION(clGetKernelSubGroupInfo)
        INITIALIZE_FUNCTION(clWaitForEvents)
        INITIALIZE_FUNCTION(clGetEventInfo)
        INITIALIZE_FUNCTION(clCreateUserEvent)
        INITIALIZE_FUNCTION(clRetainEvent)
        INITIALIZE_FUNCTION(clReleaseEvent)
        INITIALIZE_FUNCTION(clSetUserEventStatus)
        INITIALIZE_FUNCTION(clSetEventCallback)
        INITIALIZE_FUNCTION(clGetEventProfilingInfo)
        INITIALIZE_FUNCTION(clFlush)
        INITIALIZE_FUNCTION(clFinish)
        INITIALIZE_FUNCTION(clEnqueueReadBuffer)
        INITIALIZE_FUNCTION(clEnqueueReadBufferRect)
        INITIALIZE_FUNCTION(clEnqueueWriteBuffer)
        INITIALIZE_FUNCTION(clEnqueueWriteBufferRect)
        INITIALIZE_FUNCTION(clEnqueueFillBuffer)
        INITIALIZE_FUNCTION(clEnqueueCopyBuffer)
        INITIALIZE_FUNCTION(clEnqueueCopyBufferRect)
        INITIALIZE_FUNCTION(clEnqueueReadImage)
        INITIALIZE_FUNCTION(clEnqueueWriteImage)
        INITIALIZE_FUNCTION(clEnqueueFillImage)
        INITIALIZE_FUNCTION(clEnqueueCopyImage)
        INITIALIZE_FUNCTION(clEnqueueCopyImageToBuffer)
        INITIALIZE_FUNCTION(clEnqueueCopyBufferToImage)
        INITIALIZE_FUNCTION(clEnqueueMapBuffer)
        INITIALIZE_FUNCTION(clEnqueueMapImage)
        INITIALIZE_FUNCTION(clEnqueueUnmapMemObject)
        INITIALIZE_FUNCTION(clEnqueueMigrateMemObjects)
        INITIALIZE_FUNCTION(clEnqueueNDRangeKernel)
        INITIALIZE_FUNCTION(clEnqueueNativeKernel)
        INITIALIZE_FUNCTION(clEnqueueMarkerWithWaitList)
        INITIALIZE_FUNCTION(clEnqueueBarrierWithWaitList)
        INITIALIZE_FUNCTION(clEnqueueSVMFree)
        INITIALIZE_FUNCTION(clEnqueueSVMMemcpy)
        INITIALIZE_FUNCTION(clEnqueueSVMMemFill)
        INITIALIZE_FUNCTION(clEnqueueSVMMap)
        INITIALIZE_FUNCTION(clEnqueueSVMUnmap)
        INITIALIZE_FUNCTION(clEnqueueSVMMigrateMem)
        INITIALIZE_FUNCTION(clGetExtensionFunctionAddressForPlatform)
        INITIALIZE_FUNCTION(clSetCommandQueueProperty)
        INITIALIZE_FUNCTION(clCreateImage2D)
        INITIALIZE_FUNCTION(clCreateImage3D)
        INITIALIZE_FUNCTION(clEnqueueMarker)
        INITIALIZE_FUNCTION(clEnqueueWaitForEvents)
        INITIALIZE_FUNCTION(clEnqueueBarrier)
        INITIALIZE_FUNCTION(clUnloadCompiler)
        INITIALIZE_FUNCTION(clGetExtensionFunctionAddress)
        INITIALIZE_FUNCTION(clCreateCommandQueue)
        INITIALIZE_FUNCTION(clCreateSampler)
        INITIALIZE_FUNCTION(clEnqueueTask)
    }
}
jo_liczba CL_API_CALL joPobierzIdentyfikatoryPlatform(
    jo_liczba_bz liczba_wpisow,
    jo_identyfikator_platformy* platformy,
    jo_liczba_bz* liczba_platform
) {
    _joInicjalizuj();
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetPlatformIDs);
    return dispatch.clGetPlatformIDs(liczba_wpisow, platformy, liczba_platform);
}

jo_liczba CL_API_CALL joPobierzInformacjePlatformy(
    jo_identyfikator_platformy platforma,
    jo_informacje_platformy parametr,
    rozmiar_t wielkosc_parametru,
    pustka* wartosc_parametru,
    rozmiar_t* wielkosci_parametru_zwrocona
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetPlatformInfo);
    return dispatch.clGetPlatformInfo(platforma, parametr, wielkosc_parametru, wartosc_parametru, wielkosci_parametru_zwrocona);
}

jo_liczba CL_API_CALL joPobierzIdentyfikatoryUrzadzenia(
    jo_identyfikator_platformy platforma,
    jo_typ_urzadzenia typ_urzadzenia,
    jo_liczba_bz liczba_wpisow,
    jo_identyfikator_urzadzenia* urzadzenia,
    jo_liczba_bz* liczba_urzadzen
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetDeviceIDs);
    return dispatch.clGetDeviceIDs(platforma, typ_urzadzenia, liczba_wpisow, urzadzenia, liczba_urzadzen);
}

jo_liczba CL_API_CALL joPobierzInformacjeUrzadzenia(
    jo_identyfikator_urzadzenia urzadzenie,
    jo_informacje_urzadzenia parametr,
    rozmiar_t wielkosc_parametru,
    pustka* wartosc_parametru,
    rozmiar_t* wielkosci_parametru_zwrocona
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetDeviceInfo);
    return dispatch.clGetDeviceInfo(urzadzenie, parametr, wielkosc_parametru, wartosc_parametru, wielkosci_parametru_zwrocona);
}

jo_liczba CL_API_CALL joStworzPodUrzadzenia(
    jo_identyfikator_urzadzenia urzadzenie,
    const jo_wlasciwosc_partycjonowania_urzadzenia* wlasciwosci,
    jo_liczba_bz liczba_urzadzen,
    jo_identyfikator_urzadzenia* urzadzenia_zwrocone,
    jo_liczba_bz* liczba_urzadzen_zwrocona
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clCreateSubDevices);
    return dispatch.clCreateSubDevices(urzadzenie, wlasciwosci, liczba_urzadzen, urzadzenia_zwrocone, liczba_urzadzen_zwrocona);
}

jo_liczba CL_API_CALL joZachowajUrzadzenie(
    jo_identyfikator_urzadzenia urzadzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clRetainDevice);
    return dispatch.clRetainDevice(urzadzenie);
}

jo_liczba CL_API_CALL joZwolnijUrzadzenie(
    jo_identyfikator_urzadzenia urzadzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clReleaseDevice);
    return dispatch.clReleaseDevice(urzadzenie);
}

jo_liczba CL_API_CALL joUstawDomyslnaKolejkeRozkazowUrzadzenia(
    jo_kontekst kontekst,
    jo_identyfikator_urzadzenia urzadzenie,
    jo_kolejka_rozkazow kolejka_rozkazow
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clSetDefaultDeviceCommandQueue);
    return dispatch.clSetDefaultDeviceCommandQueue(kontekst, urzadzenie, kolejka_rozkazow);
}

jo_liczba CL_API_CALL joPobierzLicznikCzasuUrzadzeniaOrazGospodarza(
    jo_identyfikator_urzadzenia urzadzenie,
    jo_dluga_liczba_bz* znacznik_czasu_urzadzenia,
    jo_dluga_liczba_bz* znacznik_czasu_gospodarza
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetDeviceAndHostTimer);
    return dispatch.clGetDeviceAndHostTimer(urzadzenie, znacznik_czasu_urzadzenia, znacznik_czasu_gospodarza);
}

jo_liczba CL_API_CALL joPobierzLicznikCzasuGospodarza(
    jo_identyfikator_urzadzenia urzadzenie,
    jo_dluga_liczba_bz* znacznik_czasu_gospodarza
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetHostTimer);
    return dispatch.clGetHostTimer(urzadzenie, znacznik_czasu_gospodarza);
}

jo_kontekst CL_API_CALL joStworzKontekst(
    const jo_wlasciwosci_kontekstu* wlasciwosci,
    jo_liczba_bz liczba_urzadzen,
    const jo_identyfikator_urzadzenia* urzadzenia,
    pustka (CL_CALLBACK * funkcja_notyfikujaca)(const znak* informacje_o_bledzie,
                                                const pustka* informacje_prywatne,
                                                rozmiar_t dane,
                                                pustka* dane_uzytkownika),
    pustka* dane_uzytkownika,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreateContext, kod_bledu);
    return dispatch.clCreateContext(wlasciwosci, liczba_urzadzen, urzadzenia, funkcja_notyfikujaca, dane_uzytkownika, kod_bledu);
}

jo_kontekst CL_API_CALL joStworzKontekstZTypem(
    const jo_wlasciwosci_kontekstu* wlasciwosci,
    jo_typ_urzadzenia typ_urzadzenia,
    pustka (CL_CALLBACK * funkcja_notyfikujaca)(const znak* informacje_o_bledzie,
                                                const pustka* informacje_prywatne,
                                                rozmiar_t dane,
                                                pustka* dane_uzytkownika),
    pustka* dane_uzytkownika,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreateContextFromType, kod_bledu);
    return dispatch.clCreateContextFromType(wlasciwosci, typ_urzadzenia, funkcja_notyfikujaca, dane_uzytkownika, kod_bledu);
}

jo_liczba CL_API_CALL joZachowajKontekst(
    jo_kontekst kontekst
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clRetainContext);
    return dispatch.clRetainContext(kontekst);
}

jo_liczba CL_API_CALL joZwolnijKontekst(
    jo_kontekst kontekst
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clReleaseContext);
    return dispatch.clReleaseContext(kontekst);
}

jo_liczba CL_API_CALL joPobierzInformacjeKontekstu(
    jo_kontekst kontekst,
    jo_informacje_kontekstu parametr,
    rozmiar_t wielkosc_parametru,
    pustka* wartosc_parametru,
    rozmiar_t* wielkosci_parametru_zwrocona
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetContextInfo);
    return dispatch.clGetContextInfo(kontekst, parametr, wielkosc_parametru, wartosc_parametru, wielkosci_parametru_zwrocona);
}

jo_liczba CL_API_CALL joUstawWywolanieZwrotneDestruktora(
    jo_kontekst kontekst,
    pustka (CL_CALLBACK * funkcja_notyfikujaca)(jo_kontekst kontekst,
                                                pustka* dane_uzytkownika),
    pustka* dane_uzytkownika
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clSetContextDestructorCallback);
    return dispatch.clSetContextDestructorCallback(kontekst, funkcja_notyfikujaca, dane_uzytkownika);
}

jo_kolejka_rozkazow CL_API_CALL joStworzKolejkeRozkazowZWlasciwosciami(
    jo_kontekst kontekst,
    jo_identyfikator_urzadzenia urzadzenie,
    const jo_wlasciwosci_kolejki_rozkazow* wlasciwosci,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreateCommandQueueWithProperties, kod_bledu);
    return dispatch.clCreateCommandQueueWithProperties(kontekst, urzadzenie, wlasciwosci, kod_bledu);
}

jo_liczba CL_API_CALL joZachowajKolejkeRozkazow(
    jo_kolejka_rozkazow kolejka_rozkazow
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clRetainCommandQueue);
    return dispatch.clRetainCommandQueue(kolejka_rozkazow);
}

jo_liczba CL_API_CALL joZwolnijKolejekRozkazow(
    jo_kolejka_rozkazow kolejka_rozkazow
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clReleaseCommandQueue);
    return dispatch.clReleaseCommandQueue(kolejka_rozkazow);
}

jo_liczba CL_API_CALL joPobierzInformacjiKolejkiRozkazow(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_informacje_kolejki_rozkazow parametr,
    rozmiar_t wielkosc_parametru,
    pustka* wartosc_parametru,
    rozmiar_t* wielkosci_parametru_zwrocona
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetCommandQueueInfo);
    return dispatch.clGetCommandQueueInfo(kolejka_rozkazow, parametr, wielkosc_parametru, wartosc_parametru, wielkosci_parametru_zwrocona);
}

jo_pamiec CL_API_CALL joStworzBufor(
    jo_kontekst kontekst,
    jo_flagi_pamieci flagi,
    rozmiar_t rozmiar,
    pustka* wskaznik_gospodarza,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreateBuffer, kod_bledu);
    return dispatch.clCreateBuffer(kontekst, flagi, rozmiar, wskaznik_gospodarza, kod_bledu);
}

jo_pamiec CL_API_CALL joStworzPodBufor(
    jo_pamiec bufor,
    jo_flagi_pamieci flagi,
    jo_typ_stworzenia_buforu typ_tworzenia_buforu,
    const pustka* informacje_tworzenia_buforu,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreateSubBuffer, kod_bledu);
    return dispatch.clCreateSubBuffer(bufor, flagi, typ_tworzenia_buforu, informacje_tworzenia_buforu, kod_bledu);
}

jo_pamiec CL_API_CALL joStworzObraz(
    jo_kontekst kontekst,
    jo_flagi_pamieci flagi,
    const jo_format_obrazu* format_obrazu,
    const jo_opis_obrazu* opis_obrazu,
    pustka* wskaznik_gospodarza,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreateImage, kod_bledu);
    return dispatch.clCreateImage(kontekst, flagi, (const cl_image_format*) format_obrazu, (const cl_image_desc*) opis_obrazu, wskaznik_gospodarza, kod_bledu);
}

jo_pamiec CL_API_CALL joStworzRure(
    jo_kontekst kontekst,
    jo_flagi_pamieci flagi,
    jo_liczba_bz maksymalny_rozmiar_pakietu_rury,
    jo_liczba_bz maksymalna_liczba_pakietow_rury,
    const jo_wlasciwosci_rury* wlasciwosci,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreatePipe, kod_bledu);
    return dispatch.clCreatePipe(kontekst, flagi, maksymalny_rozmiar_pakietu_rury, maksymalna_liczba_pakietow_rury, wlasciwosci, kod_bledu);
}

jo_pamiec CL_API_CALL joStworzBuforZWlasciwosciami(
    jo_kontekst kontekst,
    const jo_wlasciwosci_pamieci* wlasciwosci,
    jo_flagi_pamieci flagi,
    rozmiar_t rozmiar,
    pustka* wskaznik_gospodarza,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreateBufferWithProperties, kod_bledu);
    return dispatch.clCreateBufferWithProperties(kontekst, wlasciwosci, flagi, rozmiar, wskaznik_gospodarza, kod_bledu);
}

jo_pamiec CL_API_CALL joStworzObrazZWlasciwosciami(
    jo_kontekst kontekst,
    const jo_wlasciwosci_pamieci* wlasciwosci,
    jo_flagi_pamieci flagi,
    const jo_format_obrazu* format_obrazu,
    const jo_opis_obrazu* opis_obrazu,
    pustka* wskaznik_gospodarza,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreateImageWithProperties, kod_bledu);
    return dispatch.clCreateImageWithProperties(kontekst, wlasciwosci, flagi, (const cl_image_format*) format_obrazu, (const cl_image_desc*) opis_obrazu, wskaznik_gospodarza, kod_bledu);
}

jo_liczba CL_API_CALL joZachowajObiektPamieci(
    jo_pamiec obiekt_pamieci
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clRetainMemObject);
    return dispatch.clRetainMemObject(obiekt_pamieci);
}

jo_liczba CL_API_CALL joZwolnijObiektPamieci(
    jo_pamiec obiekt_pamieci
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clReleaseMemObject);
    return dispatch.clReleaseMemObject(obiekt_pamieci);
}

jo_liczba CL_API_CALL joPobierzWspieraneFormatyObrazow(
    jo_kontekst kontekst,
    jo_flagi_pamieci flagi,
    jo_typ_obiektu_pamieci typ_obrazu,
    jo_liczba_bz liczba_wpisow,
    jo_format_obrazu* formaty_obrazu,
    jo_liczba_bz* liczba_formatow_obrazu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetSupportedImageFormats);
    return dispatch.clGetSupportedImageFormats(kontekst, flagi, typ_obrazu, liczba_wpisow, (cl_image_format*) formaty_obrazu, liczba_formatow_obrazu);
}

jo_liczba CL_API_CALL joPobierzInformacjeObiektuPamieci(
    jo_pamiec obiekt_pamieci,
    jo_informacje_pamieci parametr,
    rozmiar_t wielkosc_parametru,
    pustka* wartosc_parametru,
    rozmiar_t* wielkosci_parametru_zwrocona
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetMemObjectInfo);
    return dispatch.clGetMemObjectInfo(obiekt_pamieci, parametr, wielkosc_parametru, wartosc_parametru, wielkosci_parametru_zwrocona);
}

jo_liczba CL_API_CALL joPobierzInformacjeObrazu(
    jo_pamiec obraz,
    jo_informacje_obrazu parametr,
    rozmiar_t wielkosc_parametru,
    pustka* wartosc_parametru,
    rozmiar_t* wielkosci_parametru_zwrocona
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetImageInfo);
    return dispatch.clGetImageInfo(obraz, parametr, wielkosc_parametru, wartosc_parametru, wielkosci_parametru_zwrocona);
}

jo_liczba CL_API_CALL joPobierzInformacjeRury(
    jo_pamiec rura,
    jo_informacje_rury parametr,
    rozmiar_t wielkosc_parametru,
    pustka* wartosc_parametru,
    rozmiar_t* wielkosci_parametru_zwrocona
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetPipeInfo);
    return dispatch.clGetPipeInfo(rura, parametr, wielkosc_parametru, wartosc_parametru, wielkosci_parametru_zwrocona);
}

jo_liczba CL_API_CALL joUstawWywolanieZwrotneDestruktoraObiektuPamieci(
    jo_pamiec obiekt_pamieci,
    pustka (CL_CALLBACK * funkcja_notyfikujaca)(jo_pamiec obiekt_pamieci,
                                                pustka* dane_uzytkownika),
    pustka* dane_uzytkownika
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clSetMemObjectDestructorCallback);
    return dispatch.clSetMemObjectDestructorCallback(obiekt_pamieci, funkcja_notyfikujaca, dane_uzytkownika);
}

pustka* CL_API_CALL joWPWAlokuj(
    jo_kontekst kontekst,
    jo_flagi_pamieci_wpw flagi,
    rozmiar_t rozmiar,
    jo_liczba_bz ulozenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_NULL(clSVMAlloc);
    return dispatch.clSVMAlloc(kontekst, flagi, rozmiar, ulozenie);
}

pustka CL_API_CALL joWPWZwolnij(
    jo_kontekst kontekst,
    pustka* wskaznik_wpw
) {
    return dispatch.clSVMFree(kontekst, wskaznik_wpw);
}

jo_probker CL_API_CALL joStworzProbkerZWlasciwosciami(
    jo_kontekst kontekst,
    const jo_wlasciwosci_probkera* wlasciwosci_probkera,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreateSamplerWithProperties, kod_bledu);
    return dispatch.clCreateSamplerWithProperties(kontekst, wlasciwosci_probkera, kod_bledu);
}

jo_liczba CL_API_CALL joZachowajProbker(
    jo_probker probker
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clRetainSampler);
    return dispatch.clRetainSampler(probker);
}

jo_liczba CL_API_CALL joZwolnijProbker(
    jo_probker probker
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clReleaseSampler);
    return dispatch.clReleaseSampler(probker);
}

jo_liczba CL_API_CALL joPobierzInformacjeProbkera(
    jo_probker probker,
    jo_informacje_probkera parametr,
    rozmiar_t wielkosc_parametru,
    pustka* wartosc_parametru,
    rozmiar_t* wielkosci_parametru_zwrocona
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetSamplerInfo);
    return dispatch.clGetSamplerInfo(probker, parametr, wielkosc_parametru, wartosc_parametru, wielkosci_parametru_zwrocona);
}

jo_program CL_API_CALL joStworzProgramZeZrodlem(
    jo_kontekst kontekst,
    jo_liczba_bz liczba,
    const znak** ciagi_znakow,
    const rozmiar_t* dlugosci,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreateProgramWithSource, kod_bledu);
    return dispatch.clCreateProgramWithSource(kontekst, liczba, ciagi_znakow, dlugosci, kod_bledu);
}

jo_program CL_API_CALL joStworzProgramZPostaciaBinarna(
    jo_kontekst kontekst,
    jo_liczba_bz liczba_urzadzen,
    const jo_identyfikator_urzadzenia* lista_urzadzen,
    const rozmiar_t* dlugosci,
    const jo_znak_bz** postaci_binarne,
    jo_liczba* status_postaci_binarnych,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreateProgramWithBinary, kod_bledu);
    return dispatch.clCreateProgramWithBinary(kontekst, liczba_urzadzen, lista_urzadzen, dlugosci, postaci_binarne, status_postaci_binarnych, kod_bledu);
}

jo_program CL_API_CALL joStworzProgramZWbudowanymiJadrami(
    jo_kontekst kontekst,
    jo_liczba_bz liczba_urzadzen,
    const jo_identyfikator_urzadzenia* lista_urzadzen,
    const znak* nazwy_jader,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreateProgramWithBuiltInKernels, kod_bledu);
    return dispatch.clCreateProgramWithBuiltInKernels(kontekst, liczba_urzadzen, lista_urzadzen, nazwy_jader, kod_bledu);
}

jo_program CL_API_CALL joStworzProgramZPostaciaPosrednia(
    jo_kontekst kontekst,
    const pustka* postac_posrednia,
    rozmiar_t dlugosc,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreateProgramWithIL, kod_bledu);
    return dispatch.clCreateProgramWithIL(kontekst, postac_posrednia, dlugosc, kod_bledu);
}

jo_liczba CL_API_CALL joZachowajProgram(
    jo_program program
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clRetainProgram);
    return dispatch.clRetainProgram(program);
}

jo_liczba CL_API_CALL joZwolnijProgram(
    jo_program program
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clReleaseProgram);
    return dispatch.clReleaseProgram(program);
}

jo_liczba CL_API_CALL joBudujProgram(
    jo_program program,
    jo_liczba_bz liczba_urzadzen,
    const jo_identyfikator_urzadzenia* lista_urzadzen,
    const znak* opcje,
    pustka (CL_CALLBACK * funkcja_notyfikujaca)(jo_program program,
                                                pustka* dane_uzytkownika),
    pustka* dane_uzytkownika
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clBuildProgram);
    return dispatch.clBuildProgram(program, liczba_urzadzen, lista_urzadzen, opcje, funkcja_notyfikujaca, dane_uzytkownika);
}

jo_liczba CL_API_CALL joKompilujProgram(
    jo_program program,
    jo_liczba_bz liczba_urzadzen,
    const jo_identyfikator_urzadzenia* lista_urzadzen,
    const znak* opcje,
    jo_liczba_bz liczba_naglowkow_wejsciowych,
    const jo_program* pliki_naglowkowe,
    const znak** nazwy_plikow_naglowkowych,
    pustka (CL_CALLBACK * funkcja_notyfikujaca)(jo_program program,
                                                pustka* dane_uzytkownika),
    pustka* dane_uzytkownika
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clCompileProgram);
    return dispatch.clCompileProgram(program, liczba_urzadzen, lista_urzadzen, opcje, liczba_naglowkow_wejsciowych, pliki_naglowkowe, nazwy_plikow_naglowkowych, funkcja_notyfikujaca, dane_uzytkownika);
}

jo_program CL_API_CALL joKonsolidujProgram(
    jo_kontekst kontekst,
    jo_liczba_bz liczba_urzadzen,
    const jo_identyfikator_urzadzenia* lista_urzadzen,
    const znak* opcje,
    jo_liczba_bz liczba_programow_wejsciowych,
    const jo_program* programy,
    pustka (CL_CALLBACK * funkcja_notyfikujaca)(jo_program program,
                                                pustka* dane_uzytkownika),
    pustka* dane_uzytkownika,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clLinkProgram, kod_bledu);
    return dispatch.clLinkProgram(kontekst, liczba_urzadzen, lista_urzadzen, opcje, liczba_programow_wejsciowych, programy, funkcja_notyfikujaca, dane_uzytkownika, kod_bledu);
}

jo_liczba CL_API_CALL joUstawWywolanieZwrotneZwolnieniaProgramu(
    jo_program program,
    pustka (CL_CALLBACK * funkcja_notyfikujaca)(jo_program program,
                                                pustka* dane_uzytkownika),
    pustka* dane_uzytkownika
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clSetProgramReleaseCallback);
    return dispatch.clSetProgramReleaseCallback(program, funkcja_notyfikujaca, dane_uzytkownika);
}

jo_liczba CL_API_CALL joUstawStalaSpecjalizacyjnaProgramu(
    jo_program program,
    jo_liczba_bz identyfikator_specjalizacji,
    rozmiar_t rozmiar_specjalizacji,
    const pustka* wartosc_specjalizacji
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clSetProgramSpecializationConstant);
    return dispatch.clSetProgramSpecializationConstant(program, identyfikator_specjalizacji, rozmiar_specjalizacji, wartosc_specjalizacji);
}

jo_liczba CL_API_CALL joOdladujKompilatorPlatformy(
    jo_identyfikator_platformy platforma
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clUnloadPlatformCompiler);
    return dispatch.clUnloadPlatformCompiler(platforma);
}

jo_liczba CL_API_CALL joPobierzInformacjeProgramu(
    jo_program program,
    jo_informacje_programu parametr,
    rozmiar_t wielkosc_parametru,
    pustka* wartosc_parametru,
    rozmiar_t* wielkosci_parametru_zwrocona
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetProgramInfo);
    return dispatch.clGetProgramInfo(program, parametr, wielkosc_parametru, wartosc_parametru, wielkosci_parametru_zwrocona);
}

jo_liczba CL_API_CALL joPobierzInformacjeBudowaniaProgramu(
    jo_program program,
    jo_identyfikator_urzadzenia urzadzenie,
    jo_informacje_budowania_programu parametr,
    rozmiar_t wielkosc_parametru,
    pustka* wartosc_parametru,
    rozmiar_t* wielkosci_parametru_zwrocona
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetProgramBuildInfo);
    return dispatch.clGetProgramBuildInfo(program, urzadzenie, parametr, wielkosc_parametru, wartosc_parametru, wielkosci_parametru_zwrocona);
}

jo_jadro CL_API_CALL joStworzJadro(
    jo_program program,
    const znak* nazwa_jadra,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreateKernel, kod_bledu);
    return dispatch.clCreateKernel(program, nazwa_jadra, kod_bledu);
}

jo_liczba CL_API_CALL joStworzJadraWProgramie(
    jo_program program,
    jo_liczba_bz liczba_jader,
    jo_jadro* jadra,
    jo_liczba_bz* liczba_jader_zwrocona
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clCreateKernelsInProgram);
    return dispatch.clCreateKernelsInProgram(program, liczba_jader, jadra, liczba_jader_zwrocona);
}

jo_jadro CL_API_CALL joSklonujJadro(
    jo_jadro jadro,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCloneKernel, kod_bledu);
    return dispatch.clCloneKernel(jadro, kod_bledu);
}

jo_liczba CL_API_CALL joZachowajKernel(
    jo_jadro jadro
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clRetainKernel);
    return dispatch.clRetainKernel(jadro);
}

jo_liczba CL_API_CALL joZwolnijJadro(
    jo_jadro jadro
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clReleaseKernel);
    return dispatch.clReleaseKernel(jadro);
}

jo_liczba CL_API_CALL joUstawArgumentJadra(
    jo_jadro jadro,
    jo_liczba_bz indeks_argumentu,
    rozmiar_t rozmiar_argumentu,
    const pustka* wartosc_argumentu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clSetKernelArg);
    return dispatch.clSetKernelArg(jadro, indeks_argumentu, rozmiar_argumentu, wartosc_argumentu);
}

jo_liczba CL_API_CALL joArgumentJadraWskaznikWPW(
    jo_jadro jadro,
    jo_liczba_bz indeks_argumentu,
    const pustka* wartosc_argumentu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clSetKernelArgSVMPointer);
    return dispatch.clSetKernelArgSVMPointer(jadro, indeks_argumentu, wartosc_argumentu);
}

jo_liczba CL_API_CALL joPobierzInformacjeWykonaniaJadra(
    jo_jadro jadro,
    jo_informacje_wykonawcze_jadra parametr,
    rozmiar_t wielkosc_parametru,
    const pustka* wartosc_parametru
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clSetKernelExecInfo);
    return dispatch.clSetKernelExecInfo(jadro, parametr, wielkosc_parametru, wartosc_parametru);
}

jo_liczba CL_API_CALL joPobierzInformacjeJadra(
    jo_jadro jadro,
    jo_informacje_jadra parametr,
    rozmiar_t wielkosc_parametru,
    pustka* wartosc_parametru,
    rozmiar_t* wielkosci_parametru_zwrocona
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetKernelInfo);
    return dispatch.clGetKernelInfo(jadro, parametr, wielkosc_parametru, wartosc_parametru, wielkosci_parametru_zwrocona);
}

jo_liczba CL_API_CALL joPobierzInformacjeArgumentuJadra(
    jo_jadro jadro,
    jo_liczba_bz indeks_argumentu,
    jo_informacje_argumentu_jadra parametr,
    rozmiar_t wielkosc_parametru,
    pustka* wartosc_parametru,
    rozmiar_t* wielkosci_parametru_zwrocona
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetKernelArgInfo);
    return dispatch.clGetKernelArgInfo(jadro, indeks_argumentu, parametr, wielkosc_parametru, wartosc_parametru, wielkosci_parametru_zwrocona);
}

jo_liczba CL_API_CALL joPobierzInformacjeGrupyWykonawczejJadra(
    jo_jadro jadro,
    jo_identyfikator_urzadzenia urzadzenie,
    jo_informacje_grupy_pracowniczej parametr,
    rozmiar_t wielkosc_parametru,
    pustka* wartosc_parametru,
    rozmiar_t* wielkosci_parametru_zwrocona
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetKernelWorkGroupInfo);
    return dispatch.clGetKernelWorkGroupInfo(jadro, urzadzenie, parametr, wielkosc_parametru, wartosc_parametru, wielkosci_parametru_zwrocona);
}

jo_liczba CL_API_CALL joPobierzInformacjePodgrupyWykonawczejJadra(
    jo_jadro jadro,
    jo_identyfikator_urzadzenia urzadzenie,
    jo_informacje_podgrupy_pracowniczej parametr,
    rozmiar_t rozmiar_wartosci_wejsciowej,
    const pustka* wartosc_wejsciowa,
    rozmiar_t wielkosc_parametru,
    pustka* wartosc_parametru,
    rozmiar_t* wielkosci_parametru_zwrocona
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetKernelSubGroupInfo);
    return dispatch.clGetKernelSubGroupInfo(jadro, urzadzenie, parametr, rozmiar_wartosci_wejsciowej, wartosc_wejsciowa, wielkosc_parametru, wartosc_parametru, wielkosci_parametru_zwrocona);
}

jo_liczba CL_API_CALL joPoczekajNaZdarzenia(
    jo_liczba_bz liczba_zdarzen,
    const jo_zdarzenie* lista_zdarzen
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clWaitForEvents);
    return dispatch.clWaitForEvents(liczba_zdarzen, lista_zdarzen);
}

jo_liczba CL_API_CALL joPobierzInformacjeZdarzenia(
    jo_zdarzenie zdarzenie,
    jo_informacje_zdarzenia parametr,
    rozmiar_t wielkosc_parametru,
    pustka* wartosc_parametru,
    rozmiar_t* wielkosci_parametru_zwrocona
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetEventInfo);
    return dispatch.clGetEventInfo(zdarzenie, parametr, wielkosc_parametru, wartosc_parametru, wielkosci_parametru_zwrocona);
}

jo_zdarzenie CL_API_CALL joStworzZdarzenieUzytkownika(
    jo_kontekst kontekst,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreateUserEvent, kod_bledu);
    return dispatch.clCreateUserEvent(kontekst, kod_bledu);
}

jo_liczba CL_API_CALL joZachowajZdarzenie(
    jo_zdarzenie zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clRetainEvent);
    return dispatch.clRetainEvent(zdarzenie);
}

jo_liczba CL_API_CALL joZwolnijZdarzenie(
    jo_zdarzenie zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clReleaseEvent);
    return dispatch.clReleaseEvent(zdarzenie);
}

jo_liczba CL_API_CALL joUstawStatusZdarzeniaUzytkownika(
    jo_zdarzenie zdarzenie,
    jo_liczba status_wykonania
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clSetUserEventStatus);
    return dispatch.clSetUserEventStatus(zdarzenie, status_wykonania);
}

jo_liczba CL_API_CALL joUstawWywolanieZwrotneZdarzenia(
    jo_zdarzenie zdarzenie,
    jo_liczba typ,
    pustka (CL_CALLBACK * funkcja_notyfikujaca)(jo_zdarzenie zdarzenie,
                                                jo_liczba status_komendy_zdarzenia,
                                                pustka* dane_uzytkownika),
    pustka* dane_uzytkownika
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clSetEventCallback);
    return dispatch.clSetEventCallback(zdarzenie, typ, funkcja_notyfikujaca, dane_uzytkownika);
}

jo_liczba CL_API_CALL joPobierzInformacjeZdarzenProfilujacych(
    jo_zdarzenie zdarzenie,
    jo_informacje_profilowania parametr,
    rozmiar_t wielkosc_parametru,
    pustka* wartosc_parametru,
    rozmiar_t* wielkosci_parametru_zwrocona
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clGetEventProfilingInfo);
    return dispatch.clGetEventProfilingInfo(zdarzenie, parametr, wielkosc_parametru, wartosc_parametru, wielkosci_parametru_zwrocona);
}

jo_liczba CL_API_CALL joSpusc(
    jo_kolejka_rozkazow kolejka_rozkazow
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clFlush);
    return dispatch.clFlush(kolejka_rozkazow);
}

jo_liczba CL_API_CALL joZakoncz(
    jo_kolejka_rozkazow kolejka_rozkazow
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clFinish);
    return dispatch.clFinish(kolejka_rozkazow);
}

jo_liczba CL_API_CALL joZakolejkujCzytanieBuforu(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_pamiec bufor,
    jo_logika blokujacy_odczyt,
    rozmiar_t przesuniecie,
    rozmiar_t rozmiar,
    pustka* wsk,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueReadBuffer);
    return dispatch.clEnqueueReadBuffer(kolejka_rozkazow, bufor, blokujacy_odczyt, przesuniecie, rozmiar, wsk, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujCzytanieProstokatuBuforu(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_pamiec bufor,
    jo_logika blokujacy_odczyt,
    const rozmiar_t* poczatku_buforu,
    const rozmiar_t* poczatek_gospodarza,
    const rozmiar_t* region,
    rozmiar_t rozmiar_linii_buforu,
    rozmiar_t rozmiar_plaszczyzny_buforu,
    rozmiar_t rozmiar_linii_gospodarza,
    rozmiar_t rozmiar_plaszczyzny_gospodarza,
    pustka* wsk,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueReadBufferRect);
    return dispatch.clEnqueueReadBufferRect(kolejka_rozkazow, bufor, blokujacy_odczyt, poczatku_buforu, poczatek_gospodarza, region, rozmiar_linii_buforu, rozmiar_plaszczyzny_buforu, rozmiar_linii_gospodarza, rozmiar_plaszczyzny_gospodarza, wsk, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujPisanieBuforu(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_pamiec bufor,
    jo_logika blokujacy_zapis,
    rozmiar_t przesuniecie,
    rozmiar_t rozmiar,
    const pustka* wsk,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueWriteBuffer);
    return dispatch.clEnqueueWriteBuffer(kolejka_rozkazow, bufor, blokujacy_zapis, przesuniecie, rozmiar, wsk, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujProstokatuBuforu(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_pamiec bufor,
    jo_logika blokujacy_zapis,
    const rozmiar_t* poczatku_buforu,
    const rozmiar_t* poczatek_gospodarza,
    const rozmiar_t* region,
    rozmiar_t rozmiar_linii_buforu,
    rozmiar_t rozmiar_plaszczyzny_buforu,
    rozmiar_t rozmiar_linii_gospodarza,
    rozmiar_t rozmiar_plaszczyzny_gospodarza,
    const pustka* wsk,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueWriteBufferRect);
    return dispatch.clEnqueueWriteBufferRect(kolejka_rozkazow, bufor, blokujacy_zapis, poczatku_buforu, poczatek_gospodarza, region, rozmiar_linii_buforu, rozmiar_plaszczyzny_buforu, rozmiar_linii_gospodarza, rozmiar_plaszczyzny_gospodarza, wsk, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujWypelnianieBuforu(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_pamiec bufor,
    const pustka* wzor,
    rozmiar_t rozmiar_wzoru,
    rozmiar_t przesuniecie,
    rozmiar_t rozmiar,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueFillBuffer);
    return dispatch.clEnqueueFillBuffer(kolejka_rozkazow, bufor, wzor, rozmiar_wzoru, przesuniecie, rozmiar, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujKopiowanieBuforu(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_pamiec bufor_zrodlowy,
    jo_pamiec bufor_docelowy,
    rozmiar_t przesuniecie_zrodlowe,
    rozmiar_t przesuniecie_docelowe,
    rozmiar_t rozmiar,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueCopyBuffer);
    return dispatch.clEnqueueCopyBuffer(kolejka_rozkazow, bufor_zrodlowy, bufor_docelowy, przesuniecie_zrodlowe, przesuniecie_docelowe, rozmiar, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujKopiowanieProstokatuBuforu(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_pamiec bufor_zrodlowy,
    jo_pamiec bufor_docelowy,
    const rozmiar_t* poczatek_zrodlowy,
    const rozmiar_t* poczatek_docelowy,
    const rozmiar_t* region,
    rozmiar_t rozmiar_linii_zrodlowej,
    rozmiar_t rozmiar_plaszczyzny_zrodlowej,
    rozmiar_t rozmiar_linii_docelowej,
    rozmiar_t rozmiar_plaszczyzny_docelowej,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueCopyBufferRect);
    return dispatch.clEnqueueCopyBufferRect(kolejka_rozkazow, bufor_zrodlowy, bufor_docelowy, poczatek_zrodlowy, poczatek_docelowy, region, rozmiar_linii_zrodlowej, rozmiar_plaszczyzny_zrodlowej, rozmiar_linii_docelowej, rozmiar_plaszczyzny_docelowej, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujCzytanieObrazu(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_pamiec obraz,
    jo_logika blokujacy_odczyt,
    const rozmiar_t* poczatek,
    const rozmiar_t* region,
    rozmiar_t rozmiar_linii,
    rozmiar_t rozmiar_plaszczyzny,
    pustka* wsk,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueReadImage);
    return dispatch.clEnqueueReadImage(kolejka_rozkazow, obraz, blokujacy_odczyt, poczatek, region, rozmiar_linii, rozmiar_plaszczyzny, wsk, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujPisanieObrazu(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_pamiec obraz,
    jo_logika blokujacy_zapis,
    const rozmiar_t* poczatek,
    const rozmiar_t* region,
    rozmiar_t rozmiar_linii,
    rozmiar_t rozmiar_plaszczyzny,
    const pustka* wsk,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueWriteImage);
    return dispatch.clEnqueueWriteImage(kolejka_rozkazow, obraz, blokujacy_zapis, poczatek, region, rozmiar_linii, rozmiar_plaszczyzny, wsk, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujWypelnianieObrazu(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_pamiec obraz,
    const pustka* kolor_wypelnienia,
    const rozmiar_t* poczatek,
    const rozmiar_t* region,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueFillImage);
    return dispatch.clEnqueueFillImage(kolejka_rozkazow, obraz, kolor_wypelnienia, poczatek, region, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujKopiowanieOrazu(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_pamiec obraz_zrodlowy,
    jo_pamiec obraz_docelowy,
    const rozmiar_t* poczatek_zrodlowy,
    const rozmiar_t* poczatek_docelowy,
    const rozmiar_t* region,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueCopyImage);
    return dispatch.clEnqueueCopyImage(kolejka_rozkazow, obraz_zrodlowy, obraz_docelowy, poczatek_zrodlowy, poczatek_docelowy, region, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujKopiowanieObrazuDoBuforu(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_pamiec obraz_zrodlowy,
    jo_pamiec bufor_docelowy,
    const rozmiar_t* poczatek_zrodlowy,
    const rozmiar_t* region,
    rozmiar_t przesuniecie_docelowe,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueCopyImageToBuffer);
    return dispatch.clEnqueueCopyImageToBuffer(kolejka_rozkazow, obraz_zrodlowy, bufor_docelowy, poczatek_zrodlowy, region, przesuniecie_docelowe, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujKopiowanieBuforuDoObrazu(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_pamiec bufor_zrodlowy,
    jo_pamiec obraz_docelowy,
    rozmiar_t przesuniecie_zrodlowe,
    const rozmiar_t* poczatek_docelowy,
    const rozmiar_t* region,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueCopyBufferToImage);
    return dispatch.clEnqueueCopyBufferToImage(kolejka_rozkazow, bufor_zrodlowy, obraz_docelowy, przesuniecie_zrodlowe, poczatek_docelowy, region, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

pustka* CL_API_CALL joZakolejkujMapowanieBuforu(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_pamiec bufor,
    jo_logika blokujace_mapowanie,
    jo_flagi_mapowania flagi_mapowania,
    rozmiar_t przesuniecie,
    rozmiar_t rozmiar,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clEnqueueMapBuffer, kod_bledu);
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_NULL(clEnqueueMapBuffer);
    return dispatch.clEnqueueMapBuffer(kolejka_rozkazow, bufor, blokujace_mapowanie, flagi_mapowania, przesuniecie, rozmiar, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie, kod_bledu);
}

pustka* CL_API_CALL joZakolejkujMapowanieObrazu(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_pamiec obraz,
    jo_logika blokujace_mapowanie,
    jo_flagi_mapowania flagi_mapowania,
    const rozmiar_t* poczatek,
    const rozmiar_t* region,
    rozmiar_t* rozmiar_linii_obrazu,
    rozmiar_t* rozmiar_plaszczyzny_obrazu,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clEnqueueMapImage, kod_bledu);
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_NULL(clEnqueueMapImage);
    return dispatch.clEnqueueMapImage(kolejka_rozkazow, obraz, blokujace_mapowanie, flagi_mapowania, poczatek, region, rozmiar_linii_obrazu, rozmiar_plaszczyzny_obrazu, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie, kod_bledu);
}

jo_liczba CL_API_CALL joZakolejkujOdmapowanieObiektuPamieci(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_pamiec obiekt_pamieci,
    pustka* zamapowany_wskaznik,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueUnmapMemObject);
    return dispatch.clEnqueueUnmapMemObject(kolejka_rozkazow, obiekt_pamieci, zamapowany_wskaznik, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujMigracjowanieObiektowPamieci(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_liczba_bz liczba_obiektow_pamieci,
    const jo_pamiec* obiekty_pamieci,
    jo_flagi_przesiedlenia_pamieci flagi,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueMigrateMemObjects);
    return dispatch.clEnqueueMigrateMemObjects(kolejka_rozkazow, liczba_obiektow_pamieci, obiekty_pamieci, flagi, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujJadroZakresuND(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_jadro jadro,
    jo_liczba_bz wymiary_pracy,
    const rozmiar_t* globalny_przesuniecie_pracy,
    const rozmiar_t* globalny_rozmiar_pracy,
    const rozmiar_t* lokalny_rozmiar_pracy,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueNDRangeKernel);
    return dispatch.clEnqueueNDRangeKernel(kolejka_rozkazow, jadro, wymiary_pracy, globalny_przesuniecie_pracy, globalny_rozmiar_pracy, lokalny_rozmiar_pracy, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujJadroNatywne(
    jo_kolejka_rozkazow kolejka_rozkazow,
    pustka (CL_CALLBACK * funkcja_uzytkownika)(pustka*),
    pustka* argumenty,
    rozmiar_t liczba_argumentow,
    jo_liczba_bz liczba_obiektow_pamieci,
    const jo_pamiec* lista_obiektow_pamieci,
    const pustka** lokacja_argumentow_pamieciowych,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueNativeKernel);
    return dispatch.clEnqueueNativeKernel(kolejka_rozkazow, funkcja_uzytkownika, argumenty, liczba_argumentow, liczba_obiektow_pamieci, lista_obiektow_pamieci, lokacja_argumentow_pamieciowych, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujZnacznikZListaOczekiwania(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueMarkerWithWaitList);
    return dispatch.clEnqueueMarkerWithWaitList(kolejka_rozkazow, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujBariereZListaOczekiwanie(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueBarrierWithWaitList);
    return dispatch.clEnqueueBarrierWithWaitList(kolejka_rozkazow, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujZwalnianieWPW(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_liczba_bz liczba_wskaznikow_wpw,
    pustka* wskazniki_wpw[],
    pustka (CL_CALLBACK * wsk_funkcja_zwalniajaca)(jo_kolejka_rozkazow kolejka_rozkazow,
                                                   jo_liczba_bz liczba_wskaznikow_wpw,
                                                   pustka* wskazniki_wpw[],
                                                   pustka* dane_uzytkownika),
    pustka* dane_uzytkownika,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueSVMFree);
    return dispatch.clEnqueueSVMFree(kolejka_rozkazow, liczba_wskaznikow_wpw, wskazniki_wpw, wsk_funkcja_zwalniajaca, dane_uzytkownika, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujKopiowanieWPW(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_logika blokujaca_kopia,
    pustka* wskaznik_docelowy,
    const pustka* wskaznik_zrodlowy,
    rozmiar_t rozmiar,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueSVMMemcpy);
    return dispatch.clEnqueueSVMMemcpy(kolejka_rozkazow, blokujaca_kopia, wskaznik_docelowy, wskaznik_zrodlowy, rozmiar, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujWypelnianieWPW(
    jo_kolejka_rozkazow kolejka_rozkazow,
    pustka* wskaznik_wpw,
    const pustka* wzor,
    rozmiar_t rozmiar_wzoru,
    rozmiar_t rozmiar,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueSVMMemFill);
    return dispatch.clEnqueueSVMMemFill(kolejka_rozkazow, wskaznik_wpw, wzor, rozmiar_wzoru, rozmiar, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujMapowanieWPW(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_logika blokujace_mapowanie,
    jo_flagi_mapowania flagi,
    pustka* wskaznik_wpw,
    rozmiar_t rozmiar,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueSVMMap);
    return dispatch.clEnqueueSVMMap(kolejka_rozkazow, blokujace_mapowanie, flagi, wskaznik_wpw, rozmiar, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujOdmapowanieWPW(
    jo_kolejka_rozkazow kolejka_rozkazow,
    pustka* wskaznik_wpw,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueSVMUnmap);
    return dispatch.clEnqueueSVMUnmap(kolejka_rozkazow, wskaznik_wpw, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujMigrowanieWPW(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_liczba_bz liczba_wskaznikow_wpw,
    const pustka** wskazniki_wpw,
    const rozmiar_t* rozmiary,
    jo_flagi_przesiedlenia_pamieci flagi,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueSVMMigrateMem);
    return dispatch.clEnqueueSVMMigrateMem(kolejka_rozkazow, liczba_wskaznikow_wpw, wskazniki_wpw, rozmiary, flagi, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}

pustka* CL_API_CALL joPobierzAdresFunkcjiRozszerzeniaDlaPlatformy(
    jo_identyfikator_platformy platforma,
    const znak* nazwa_funkcji
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_NULL(clGetExtensionFunctionAddressForPlatform);
    return dispatch.clGetExtensionFunctionAddressForPlatform(platforma, nazwa_funkcji);
}

jo_liczba CL_API_CALL joUstawWlasciwoscKolejkiRozkazow(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_wlasciwosci_kolejki_rozkazow wlasciwosci,
    jo_logika wlacz,
    jo_wlasciwosci_kolejki_rozkazow* stare_wlasciwosci
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clSetCommandQueueProperty);
    return dispatch.clSetCommandQueueProperty(kolejka_rozkazow, wlasciwosci, wlacz, stare_wlasciwosci);
}

jo_pamiec CL_API_CALL joStworzObraz2D(
    jo_kontekst kontekst,
    jo_flagi_pamieci flagi,
    const jo_format_obrazu* format_obrazu,
    rozmiar_t szerokosc_obrazu,
    rozmiar_t wysokosc_obrazu,
    rozmiar_t rozmiar_linii_obrazu,
    pustka* wskaznik_gospodarza,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreateImage2D, kod_bledu);
    return dispatch.clCreateImage2D(kontekst, flagi, (const cl_image_format*) format_obrazu, szerokosc_obrazu, wysokosc_obrazu, rozmiar_linii_obrazu, wskaznik_gospodarza, kod_bledu);
}

jo_pamiec CL_API_CALL joStworzObraz3D(
    jo_kontekst kontekst,
    jo_flagi_pamieci flagi,
    const jo_format_obrazu* format_obrazu,
    rozmiar_t szerokosc_obrazu,
    rozmiar_t wysokosc_obrazu,
    rozmiar_t glebokosc_obrazu,
    rozmiar_t rozmiar_linii_obrazu,
    rozmiar_t rozmiar_plaszczyzny_obrazu,
    pustka* wskaznik_gospodarza,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreateImage3D, kod_bledu);
    return dispatch.clCreateImage3D(kontekst, flagi, (const cl_image_format*) format_obrazu, szerokosc_obrazu, wysokosc_obrazu, glebokosc_obrazu, rozmiar_linii_obrazu, rozmiar_plaszczyzny_obrazu, wskaznik_gospodarza, kod_bledu);
}

jo_liczba CL_API_CALL joStworzZnacznik(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueMarker);
    return dispatch.clEnqueueMarker(kolejka_rozkazow, zdarzenie);
}

jo_liczba CL_API_CALL joZakolejkujOczekiwanieNaZdarzenia(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_liczba_bz liczba_zdarzen,
    const jo_zdarzenie* lista_zdarzen
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueWaitForEvents);
    return dispatch.clEnqueueWaitForEvents(kolejka_rozkazow, liczba_zdarzen, lista_zdarzen);
}

jo_liczba CL_API_CALL joZakolejkujBariere(
    jo_kolejka_rozkazow kolejka_rozkazow
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueBarrier);
    return dispatch.clEnqueueBarrier(kolejka_rozkazow);
}

jo_liczba CL_API_CALL joOdladujKompilator(
    pustka
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clUnloadCompiler);
    return dispatch.clUnloadCompiler();
}

pustka* CL_API_CALL joPobierzAdresFunkcjiRozszerzenia(
    const znak* nazwa_funkcji
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_NULL(clGetExtensionFunctionAddress);
    return dispatch.clGetExtensionFunctionAddress(nazwa_funkcji);
}

jo_kolejka_rozkazow CL_API_CALL joStworzKolejkeRozkazow(
    jo_kontekst kontekst,
    jo_identyfikator_urzadzenia urzadzenie,
    jo_wlasciwosci_kolejki_rozkazow wlasciwosci,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreateCommandQueue, kod_bledu);
    return dispatch.clCreateCommandQueue(kontekst, urzadzenie, wlasciwosci, kod_bledu);
}

jo_probker CL_API_CALL joStworzProbker(
    jo_kontekst kontekst,
    jo_logika wspolrzedne_znormalizowane,
    jo_tryb_adresowania tryb_adresowania,
    jo_tryb_filtrowania tryb_filtrowania,
    jo_liczba* kod_bledu
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(clCreateSampler, kod_bledu);
    return dispatch.clCreateSampler(kontekst, wspolrzedne_znormalizowane, tryb_adresowania, tryb_filtrowania, kod_bledu);
}

jo_liczba CL_API_CALL joZakolejkujZadanie(
    jo_kolejka_rozkazow kolejka_rozkazow,
    jo_jadro jadro,
    jo_liczba_bz liczba_zdarzen_na_liscie_oczekiwan,
    const jo_zdarzenie* lista_oczekiwan,
    jo_zdarzenie* zdarzenie
) {
    VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(clEnqueueTask);
    return dispatch.clEnqueueTask(kolejka_rozkazow, jadro, liczba_zdarzen_na_liscie_oczekiwan, lista_oczekiwan, zdarzenie);
}
