<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="11008008">
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
		<Item Name="AtomicConsole.exe" Type="Document" URL="../AtomicConsole.exe"/>
		<Item Name="DeployMe.vi" Type="VI" URL="../DeployMe.vi"/>
		<Item Name="MyClass.lvclass" Type="LVClass" URL="../MyClass.lvclass"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="NationalInstruments.TestStand.Utility.dll" Type="Document" URL="../../../../../Dev/tsdev/Dev/5.1/App/TestStand/Components/Tools/MigrationUtility/NationalInstruments.TestStand.Utility.dll"/>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
