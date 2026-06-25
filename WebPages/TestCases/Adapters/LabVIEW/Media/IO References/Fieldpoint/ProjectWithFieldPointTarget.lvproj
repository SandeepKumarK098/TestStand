<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="15008000">
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
		<Item Name="Dependencies" Type="Dependencies"/>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
	<Item Name="FP Res " Type="FP Controller (Non RT)">
		<Property Name="alias.name" Type="Str">FP Res </Property>
		<Property Name="alias.value" Type="Str">0.0.0.0</Property>
		<Property Name="Bound" Type="Bool">false</Property>
		<Property Name="CCSymbols" Type="Str">RT,1;FP,1;</Property>
		<Property Name="Type" Type="Str">cFP-180x</Property>
		<Item Name="cFP-180x @0" Type="FP Device">
			<Item Name="User LED" Type="FP Point"/>
		</Item>
	</Item>
</Project>
