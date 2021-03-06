/*
 Source File : PDFPageDriver.h
 
 
 Copyright 2013 Gal Kahana HummusJS
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 
 */
#pragma once

#include <node.h>

#include "PDFWriter.h"
#include "PDFEmbedParameterTypes.h"

class PDFWriterDriver : public node::ObjectWrap
{
public:
    static void Init();
    static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args);

    PDFHummus::EStatusCode StartPDF(const std::string& inOutputFilePath,
                                    EPDFVersion inPDFVersion);
    
    PDFHummus::EStatusCode ContinuePDF(const std::string& inOutputFilePath,
                                    const std::string& inStateFilePath);
    
    PDFHummus::EStatusCode ModifyPDF(const std::string& inSourceFile,
                                     const std::string& inOptionalOtherOutputFile);
    
private:
    PDFWriterDriver(){};
    
    static v8::Persistent<v8::Function> constructor;
    static v8::Handle<v8::Value> New(const v8::Arguments& args);
    static v8::Handle<v8::Value> End(const v8::Arguments& args);
    static v8::Handle<v8::Value> CreatePage(const v8::Arguments& args);
    static v8::Handle<v8::Value> WritePage(const v8::Arguments& args);
    static v8::Handle<v8::Value> StartPageContentContext(const v8::Arguments& args);
    static v8::Handle<v8::Value> PausePageContentContext(const v8::Arguments& args);
    static v8::Handle<v8::Value> CreateFormXObject(const v8::Arguments& args);
    static v8::Handle<v8::Value> EndFormXObject(const v8::Arguments& args);
    static v8::Handle<v8::Value> CreateformXObjectFromJPGFile(const v8::Arguments& args);
    static v8::Handle<v8::Value> CreateImageXObjectFromJPGFile(const v8::Arguments& args);
    static v8::Handle<v8::Value> RetrieveJPGImageInformation(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetFontForFile(const v8::Arguments& args);
    static v8::Handle<v8::Value> AttachURLLinktoCurrentPage(const v8::Arguments& args);
    static v8::Handle<v8::Value> Shutdown(const v8::Arguments& args);
    static v8::Handle<v8::Value> CreateFormXObjectFromTIFFFile(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetObjectsContext(const v8::Arguments& args);
    static v8::Handle<v8::Value> AppendPDFPagesFromPDF(const v8::Arguments& args);
    static v8::Handle<v8::Value> MergePDFPagesToPage(const v8::Arguments& args);
    static v8::Handle<v8::Value> CreatePDFCopyingContext(const v8::Arguments& args);
    static v8::Handle<v8::Value> CreateFormXObjectsFromPDF(const v8::Arguments& args);
    static v8::Handle<v8::Value> CreatePDFCopyingContextForModifiedFile(const v8::Arguments& args);
    static v8::Handle<v8::Value> CreatePDFTextString(const v8::Arguments& args);
    static v8::Handle<v8::Value> CreatePDFDate(const v8::Arguments& args);
    
    
    static CMYKRGBColor colorFromArray(v8::Handle<v8::Value> inArray);
    static PDFPageRange ObjectToPageRange(v8::Handle<v8::Object> inObject);
    
    PDFWriter mPDFWriter;
};