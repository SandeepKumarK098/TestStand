<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="8608001">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="ExpressVIDevSamples" Type="Folder">
			<Item Name="MathSampleConfig" Type="Folder">
				<Item Name="Configure MathSample.vi" Type="VI" URL="/&lt;userlib&gt;/_express/ExpressVIDevSamples/MathSampleConfig.llb/Configure MathSample.vi"/>
				<Item Name="genHelpMathSample.vi" Type="VI" URL="/&lt;userlib&gt;/_express/ExpressVIDevSamples/MathSampleConfig.llb/genHelpMathSample.vi"/>
			</Item>
			<Item Name="MathSampleSource" Type="Folder">
				<Item Name="MathSample Source.vi" Type="VI" URL="/&lt;userlib&gt;/_express/ExpressVIDevSamples/MathSampleSource.llb/MathSample Source.vi"/>
				<Item Name="subMathSample.vi" Type="VI" URL="/&lt;userlib&gt;/_express/ExpressVIDevSamples/MathSampleSource.llb/subMathSample.vi"/>
			</Item>
			<Item Name="RandomNumberConfig" Type="Folder">
				<Item Name="Configure RandomNumber.vi" Type="VI" URL="/&lt;userlib&gt;/_express/ExpressVIDevSamples/RandomNumberConfig.llb/Configure RandomNumber.vi"/>
				<Item Name="genHelpRandomNumber.vi" Type="VI" URL="/&lt;userlib&gt;/_express/ExpressVIDevSamples/RandomNumberConfig.llb/genHelpRandomNumber.vi"/>
			</Item>
			<Item Name="RandomNumberSource" Type="Folder">
				<Item Name="RandomNumber Source.vi" Type="VI" URL="/&lt;userlib&gt;/_express/ExpressVIDevSamples/RandomNumberSource.llb/RandomNumber Source.vi"/>
				<Item Name="subRandomNumber.vi" Type="VI" URL="/&lt;userlib&gt;/_express/ExpressVIDevSamples/RandomNumberSource.llb/subRandomNumber.vi"/>
			</Item>
		</Item>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="ex_Read Properties.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_Read Properties.vi"/>
				<Item Name="ex_Get All Control Refnums.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_Get All Control Refnums.vi"/>
				<Item Name="subCalcPropPageCtlName.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/subCalcPropPageCtlName.vi"/>
				<Item Name="ex_Get CtrlRefs for PropPage.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_Get CtrlRefs for PropPage.vi"/>
				<Item Name="ex_GetAllConstantRefnums.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_GetAllConstantRefnums.vi"/>
				<Item Name="ex_Make Hidden Tag.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_Make Hidden Tag.vi"/>
				<Item Name="ex_Get Control Refnum.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_Get Control Refnum.vi"/>
				<Item Name="propPagePersistenceType.ctl" Type="VI" URL="/&lt;vilib&gt;/express/express shared/propPagePersistenceType.ctl"/>
				<Item Name="propPageData.ctl" Type="VI" URL="/&lt;vilib&gt;/express/express shared/propPageData.ctl"/>
				<Item Name="Open Express VI Help.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/Open Express VI Help.vi"/>
				<Item Name="ex_Handle Radio Buttons.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_Handle Radio Buttons.vi"/>
				<Item Name="Get Control Refnums.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/Get Control Refnums.vi"/>
				<Item Name="Get Control Refnums No Error.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/Get Control Refnums No Error.vi"/>
				<Item Name="ex_PPGetProp.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_PPGetProp.vi"/>
				<Item Name="ex_PPGetValue.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_PPGetValue.vi"/>
				<Item Name="ex_PercentGFormat.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_PercentGFormat.vi"/>
				<Item Name="ex_Change Control Caption.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_Change Control Caption.vi"/>
				<Item Name="ex_Get Renamed Ctrls Table.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_Get Renamed Ctrls Table.vi"/>
				<Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
				<Item Name="ex_Set Renamed Ctrls Table.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_Set Renamed Ctrls Table.vi"/>
				<Item Name="ex_Reconfigure.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_Reconfigure.vi"/>
				<Item Name="ex_Redrop Instance VI.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_Redrop Instance VI.vi"/>
				<Item Name="ex_Write Properties.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_Write Properties.vi"/>
				<Item Name="ex_Grow Inputs and Outputs.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_Grow Inputs and Outputs.vi"/>
			</Item>
		</Item>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="Distribute Custom Express VIs" Type="Source Distribution">
				<Property Name="Bld_buildSpecName" Type="Str">Distribute Custom Express VIs</Property>
				<Property Name="Destination[0].destName" Type="Str">Destination Directory</Property>
				<Property Name="Destination[0].path" Type="Path">../UserExpressVIs/ExpressVIs</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../UserExpressVIs/ExpressVIs/SupportVIs</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].Container.applyDestination" Type="Bool">true</Property>
				<Property Name="Source[0].destinationIndex" Type="Int">1</Property>
				<Property Name="Source[0].itemID" Type="Str">{4E158052-8497-400C-AB2F-D449ECAD9DC3}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/MathSampleConfig/Configure MathSample.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="Source[2].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[2].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/MathSampleConfig/genHelpMathSample.vi</Property>
				<Property Name="Source[2].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[2].type" Type="Str">VI</Property>
				<Property Name="Source[3].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[3].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/MathSampleSource/MathSample Source.vi</Property>
				<Property Name="Source[3].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[3].type" Type="Str">VI</Property>
				<Property Name="Source[4].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[4].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/MathSampleSource/subMathSample.vi</Property>
				<Property Name="Source[4].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[4].type" Type="Str">VI</Property>
				<Property Name="Source[5].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[5].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/RandomNumberConfig/Configure RandomNumber.vi</Property>
				<Property Name="Source[5].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[5].type" Type="Str">VI</Property>
				<Property Name="Source[6].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[6].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/RandomNumberConfig/genHelpRandomNumber.vi</Property>
				<Property Name="Source[6].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[6].type" Type="Str">VI</Property>
				<Property Name="Source[7].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[7].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/RandomNumberSource/RandomNumber Source.vi</Property>
				<Property Name="Source[7].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[7].type" Type="Str">VI</Property>
				<Property Name="Source[8].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[8].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/RandomNumberSource/subRandomNumber.vi</Property>
				<Property Name="Source[8].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[8].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">9</Property>
			</Item>
			<Item Name="Failed To Find Config VI Error" Type="Source Distribution">
				<Property Name="AB_Class_Path" Type="Path">/C/Program Files/National Instruments/LabVIEW 8.6/vi.lib/AppBuilder/AB_Classes/SourceDistribution/AB_SourceDistribution.lvclass</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Failed To Find Config VI Error</Property>
				<Property Name="Destination[0].destName" Type="Str">Destination Directory</Property>
				<Property Name="Destination[0].path" Type="Path">../UserExpressVIs/FailedToFindConfigVIError</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../UserExpressVIs/FailedToFindConfigVIError/SupportVIs</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].Container.applyDestination" Type="Bool">true</Property>
				<Property Name="Source[0].destinationIndex" Type="Int">1</Property>
				<Property Name="Source[0].itemID" Type="Str">{466516CF-E6A2-493D-A90A-A80B99E8E543}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/MathSampleConfig/Configure MathSample.vi</Property>
				<Property Name="Source[1].newName" Type="Str">Configure MathSample - Error1.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="Source[2].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[2].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/MathSampleConfig/genHelpMathSample.vi</Property>
				<Property Name="Source[2].newName" Type="Str">genHelpMathSample - Error1.vi</Property>
				<Property Name="Source[2].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[2].type" Type="Str">VI</Property>
				<Property Name="Source[3].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[3].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/MathSampleSource/MathSample Source.vi</Property>
				<Property Name="Source[3].newName" Type="Str">MathSample Source - Error1.vi</Property>
				<Property Name="Source[3].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[3].type" Type="Str">VI</Property>
				<Property Name="Source[4].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[4].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/MathSampleSource/subMathSample.vi</Property>
				<Property Name="Source[4].newName" Type="Str">subMathSample - Error1.vi</Property>
				<Property Name="Source[4].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[4].type" Type="Str">VI</Property>
				<Property Name="Source[5].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[5].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/RandomNumberConfig/Configure RandomNumber.vi</Property>
				<Property Name="Source[5].newName" Type="Str">Configure RandomNumber - Error1.vi</Property>
				<Property Name="Source[5].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[5].type" Type="Str">VI</Property>
				<Property Name="Source[6].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[6].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/RandomNumberConfig/genHelpRandomNumber.vi</Property>
				<Property Name="Source[6].newName" Type="Str">genHelpRandomNumber - Error1.vi</Property>
				<Property Name="Source[6].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[6].type" Type="Str">VI</Property>
				<Property Name="Source[7].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[7].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/RandomNumberSource/RandomNumber Source.vi</Property>
				<Property Name="Source[7].newName" Type="Str">RandomNumber Source - Error1.vi</Property>
				<Property Name="Source[7].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[7].type" Type="Str">VI</Property>
				<Property Name="Source[8].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[8].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/RandomNumberSource/subRandomNumber.vi</Property>
				<Property Name="Source[8].newName" Type="Str">subRandomNumber - Error1.vi</Property>
				<Property Name="Source[8].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[8].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">9</Property>
			</Item>
			<Item Name="Invalid Config VI Prototype Error" Type="Source Distribution">
				<Property Name="AB_Class_Path" Type="Path">/C/Program Files/National Instruments/LabVIEW 8.6/vi.lib/AppBuilder/AB_Classes/SourceDistribution/AB_SourceDistribution.lvclass</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Invalid Config VI Prototype Error</Property>
				<Property Name="Destination[0].destName" Type="Str">Destination Directory</Property>
				<Property Name="Destination[0].path" Type="Path">../UserExpressVIs/InvalidConfigPrototypeError</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../UserExpressVIs/InvalidConfigPrototypeError/SupportVIs</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].Container.applyDestination" Type="Bool">true</Property>
				<Property Name="Source[0].destinationIndex" Type="Int">1</Property>
				<Property Name="Source[0].itemID" Type="Str">{466516CF-E6A2-493D-A90A-A80B99E8E543}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/MathSampleConfig/Configure MathSample.vi</Property>
				<Property Name="Source[1].newName" Type="Str">Configure MathSample - Error2.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="Source[2].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[2].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/MathSampleConfig/genHelpMathSample.vi</Property>
				<Property Name="Source[2].newName" Type="Str">genHelpMathSample - Error2.vi</Property>
				<Property Name="Source[2].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[2].type" Type="Str">VI</Property>
				<Property Name="Source[3].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[3].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/MathSampleSource/MathSample Source.vi</Property>
				<Property Name="Source[3].newName" Type="Str">MathSample Source - Error2.vi</Property>
				<Property Name="Source[3].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[3].type" Type="Str">VI</Property>
				<Property Name="Source[4].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[4].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/MathSampleSource/subMathSample.vi</Property>
				<Property Name="Source[4].newName" Type="Str">subMathSample - Error2.vi</Property>
				<Property Name="Source[4].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[4].type" Type="Str">VI</Property>
				<Property Name="Source[5].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[5].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/RandomNumberConfig/Configure RandomNumber.vi</Property>
				<Property Name="Source[5].newName" Type="Str">Configure RandomNumber - Error2.vi</Property>
				<Property Name="Source[5].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[5].type" Type="Str">VI</Property>
				<Property Name="Source[6].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[6].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/RandomNumberConfig/genHelpRandomNumber.vi</Property>
				<Property Name="Source[6].newName" Type="Str">genHelpRandomNumber - Error2.vi</Property>
				<Property Name="Source[6].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[6].type" Type="Str">VI</Property>
				<Property Name="Source[7].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[7].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/RandomNumberSource/RandomNumber Source.vi</Property>
				<Property Name="Source[7].newName" Type="Str">RandomNumber Source - Error2.vi</Property>
				<Property Name="Source[7].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[7].type" Type="Str">VI</Property>
				<Property Name="Source[8].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[8].itemID" Type="Ref">/My Computer/ExpressVIDevSamples/RandomNumberSource/subRandomNumber.vi</Property>
				<Property Name="Source[8].newName" Type="Str">subRandomNumber - Error2.vi</Property>
				<Property Name="Source[8].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[8].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">9</Property>
			</Item>
		</Item>
	</Item>
</Project>
