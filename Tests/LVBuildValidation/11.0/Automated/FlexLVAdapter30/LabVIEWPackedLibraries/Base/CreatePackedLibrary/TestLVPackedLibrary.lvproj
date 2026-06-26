<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="11006073">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="NI.SortType" Type="Int">3</Property>
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Base.lvlib" Type="Library" URL="../Base.lvlib"/>
		<Item Name="Dependencies" Type="Dependencies"/>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="Test Packed Library" Type="Packed Library">
				<Property Name="Bld_buildCacheID" Type="Str">{C02200E8-A443-403F-B732-DE12826267DB}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Test Packed Library</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../CreatePackedLibrary/build</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{7A362A28-B91C-4A2C-A9DF-25C4B1FB2BBA}</Property>
				<Property Name="Destination[0].destName" Type="Str">TestLVPackedLibrary.lvlibp</Property>
				<Property Name="Destination[0].path" Type="Path">../CreatePackedLibrary/build/NI_AB_PROJECTNAME.lvlibp</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../CreatePackedLibrary/build</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="PackedLib_callersAdapt" Type="Bool">true</Property>
				<Property Name="Source[0].itemID" Type="Str">{55B1936C-0FCD-4564-BFC2-1F2AD1B77029}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Base.lvlib</Property>
				<Property Name="Source[1].Library.allowMissingMembers" Type="Bool">true</Property>
				<Property Name="Source[1].Library.atomicCopy" Type="Bool">true</Property>
				<Property Name="Source[1].Library.LVLIBPtopLevel" Type="Bool">true</Property>
				<Property Name="Source[1].preventRename" Type="Bool">true</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">Library</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_autoIncrement" Type="Bool">true</Property>
				<Property Name="TgtF_enableDebugging" Type="Bool">true</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Test Packed Library</Property>
				<Property Name="TgtF_fileVersion.build" Type="Int">18</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Test Packed Library</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2010 </Property>
				<Property Name="TgtF_productName" Type="Str">Test Packed Library</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{CA12A070-8B34-4B58-A65D-97A736602F38}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">TestLVPackedLibrary.lvlibp</Property>
			</Item>
			<Item Name="Test Packed Library for Projects" Type="Packed Library">
				<Property Name="Bld_buildCacheID" Type="Str">{3A4C86AF-F29D-40CB-B4EC-C887B76ECF14}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Test Packed Library for Projects</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../CreatePackedLibrary/build</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{B2EA5298-7A5C-4419-AF14-AFBE31907D00}</Property>
				<Property Name="Destination[0].destName" Type="Str">TestLVPackedLibraryForProjects.lvlibp</Property>
				<Property Name="Destination[0].path" Type="Path">../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../CreatePackedLibrary/build</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="PackedLib_callersAdapt" Type="Bool">true</Property>
				<Property Name="Source[0].itemID" Type="Str">{AF70FF13-5DFC-4E90-84E5-CF91DD134D07}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Base.lvlib</Property>
				<Property Name="Source[1].Library.allowMissingMembers" Type="Bool">true</Property>
				<Property Name="Source[1].Library.atomicCopy" Type="Bool">true</Property>
				<Property Name="Source[1].Library.LVLIBPtopLevel" Type="Bool">true</Property>
				<Property Name="Source[1].preventRename" Type="Bool">true</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">Library</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_autoIncrement" Type="Bool">true</Property>
				<Property Name="TgtF_enableDebugging" Type="Bool">true</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Test Packed Library</Property>
				<Property Name="TgtF_fileVersion.build" Type="Int">19</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Test Packed Library</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2010 </Property>
				<Property Name="TgtF_productName" Type="Str">Test Packed Library</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{4EDF9AA5-79BA-4CAD-829D-C6E927A618A8}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">TestLVPackedLibraryForProjects.lvlibp</Property>
			</Item>
		</Item>
	</Item>
</Project>
