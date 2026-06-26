<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="13008000">
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
		<Item Name="PIDClass.lvclass" Type="LVClass" URL="../PIDClass.lvclass"/>
		<Item Name="test PID.vi" Type="VI" URL="../test PID.vi"/>
		<Item Name="Create PID wrapper.vi" Type="VI" URL="../Create PID wrapper.vi"/>
		<Item Name="test PID with wrappers.vi" Type="VI" URL="../test PID with wrappers.vi"/>
		<Item Name="Set Setpoint wrapper.vi" Type="VI" URL="../Set Setpoint wrapper.vi"/>
		<Item Name="Set Manual wrapper.vi" Type="VI" URL="../Set Manual wrapper.vi"/>
		<Item Name="Generate Output wrapper.vi" Type="VI" URL="../Generate Output wrapper.vi"/>
		<Item Name="Dependencies" Type="Dependencies"/>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
