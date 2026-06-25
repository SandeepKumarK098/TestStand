<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="12006134">
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
		<Item Name="ProjLib.lvlib" Type="Library" URL="../ProjLib.lvlib"/>
		<Item Name="ProjLib.lvlibp" Type="LVLibp" URL="../ProjLib.lvlibp"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="Get File Extension.vi" Type="VI" URL="../Get File Extension.vi"/>
			<Item Name="Work.vi" Type="VI" URL="../Work.vi"/>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
