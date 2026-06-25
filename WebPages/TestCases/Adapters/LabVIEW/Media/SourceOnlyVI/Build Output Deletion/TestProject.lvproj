<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="23002006">
	<Property Name="NI.LV.All.SourceOnly" Type="Bool">true</Property>
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
		<Item Name="MultiplyVI.vi" Type="VI" URL="../MultiplyVI.vi"/>
		<Item Name="TestVI.vi" Type="VI" URL="../TestVI.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="MultiplyDLL.dll" Type="Document" URL="../MultiplyDLL.dll"/>
		</Item>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="MultiplyDLL" Type="DLL">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{668A5A95-46D5-40A8-B308-2FAE1E6997D9}</Property>
				<Property Name="App_INI_GUID" Type="Str">{DD3D1358-E5EF-4506-90D1-B63BBAFE0CA4}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="App_serverType" Type="Int">0</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{4FB6A14E-58EC-4805-92A0-42CD1ACB67B8}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">MultiplyDLL</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">..</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToProject</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{7DC675D5-D53E-47E6-8A53-869C794900CD}</Property>
				<Property Name="Bld_version.build" Type="Int">1</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="Destination[0].destName" Type="Str">MultiplyDLL.dll</Property>
				<Property Name="Destination[0].path" Type="Path">../MultiplyDLL.dll</Property>
				<Property Name="Destination[0].path.type" Type="Str">relativeToProject</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../data</Property>
				<Property Name="Destination[1].path.type" Type="Str">relativeToProject</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Dll_compatibilityWith2011" Type="Bool">false</Property>
				<Property Name="Dll_delayOSMsg" Type="Bool">true</Property>
				<Property Name="Dll_headerGUID" Type="Str">{BF4E43AA-CB16-4737-99EC-3A6D96DFDDFD}</Property>
				<Property Name="Dll_includeTypeLibrary" Type="Bool">true</Property>
				<Property Name="Dll_libGUID" Type="Str">{75BC9A29-EC8D-4586-B598-0AE4C3FAF631}</Property>
				<Property Name="Dll_privateExecSys" Type="Bool">true</Property>
				<Property Name="Source[0].itemID" Type="Str">{1FC7E13B-B647-4E38-88B0-2CBAA5FDC851}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/MultiplyVI.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">ExportedVI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">National Instruments</Property>
				<Property Name="TgtF_fileDescription" Type="Str">MultiplyDLL</Property>
				<Property Name="TgtF_internalName" Type="Str">MultiplyDLL</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2023 National Instruments</Property>
				<Property Name="TgtF_productName" Type="Str">MultiplyDLL</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{BC271ACA-1AFE-4BCC-8543-61336EA687EF}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">MultiplyDLL.dll</Property>
				<Property Name="TgtF_versionIndependent" Type="Bool">true</Property>
			</Item>
		</Item>
	</Item>
</Project>
