<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="10008000">
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
		<Item Name="TestLVPackedLibraryForProjects.lvlibp" Type="LVLibp" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp">
			<Item Name="FolderA" Type="Folder">
				<Item Name="FolderB" Type="Folder">
					<Item Name="VIInFolderB.vi" Type="VI" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/FolderA/FolderB/VIInFolderB.vi"/>
					<Item Name="VIInFolderB_2.vi" Type="VI" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/FolderA/FolderB/VIInFolderB_2.vi"/>
				</Item>
				<Item Name="VIInFolderA.vi" Type="VI" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/FolderA/VIInFolderA.vi"/>
				<Item Name="VIInFolderA_2.vi" Type="VI" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/FolderA/VIInFolderA_2.vi"/>
			</Item>
			<Item Name="FolderLLB" Type="Folder">
				<Item Name="VIInLLB.vi" Type="VI" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/FolderLLB/LLB.llb/VIInLLB.vi"/>
				<Item Name="InsideFolderLLB.vi" Type="VI" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/FolderLLB/InsideFolderLLB.vi"/>
			</Item>
			<Item Name="publicFunctionInBase.vi" Type="VI" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/publicFunctionInBase.vi"/>
			<Item Name="privateFunctionInBase.vi" Type="VI" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/privateFunctionInBase.vi"/>
			<Item Name="communityFunctionInBase.vi" Type="VI" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/communityFunctionInBase.vi"/>
			<Item Name="publicControlInBase.ctl" Type="VI" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/publicControlInBase.ctl"/>
			<Item Name="privateControlInBase.ctl" Type="VI" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/privateControlInBase.ctl"/>
			<Item Name="communityControlInBase.ctl" Type="VI" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/communityControlInBase.ctl"/>
			<Item Name="FunctionLibrary.lvlib" Type="Library" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/FunctionLibrary/FunctionLibrary.lvlib"/>
			<Item Name="ControlLibrary.lvlib" Type="Library" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/ControlLibrary/ControlLibrary.lvlib"/>
			<Item Name="DirectBaseFunctions.mnu" Type="Document" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/DirectBaseFunctions.mnu"/>
			<Item Name="LinkToDefaultFunctionLibrary.mnu" Type="Document" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/LinkToDefaultFunctionLibrary.mnu"/>
			<Item Name="LinkToOtherFunctionLibrary.mnu" Type="Document" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/LinkToOtherFunctionLibrary.mnu"/>
			<Item Name="SyncToFunctionLibraryFolder.mnu" Type="Document" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/SyncToFunctionLibraryFolder.mnu"/>
			<Item Name="DirectBaseControls.mnu" Type="Document" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/DirectBaseControls.mnu"/>
			<Item Name="LinkToDefaultControlLibrary.mnu" Type="Document" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/LinkToDefaultControlLibrary.mnu"/>
			<Item Name="LinkToOtherControlLibrary.mnu" Type="Document" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/LinkToOtherControlLibrary.mnu"/>
			<Item Name="SyncToControlLibraryFolder.mnu" Type="Document" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/SyncToControlLibraryFolder.mnu"/>
			<Item Name="SyncToFolderA.mnu" Type="Document" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/SyncToFolderA.mnu"/>
			<Item Name="SyncToFolderLLB.mnu" Type="Document" URL="../../CreatePackedLibrary/build/TestLVPackedLibraryForProjects.lvlibp/SyncToFolderLLB.mnu"/>
		</Item>
		<Item Name="Dependencies" Type="Dependencies"/>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
