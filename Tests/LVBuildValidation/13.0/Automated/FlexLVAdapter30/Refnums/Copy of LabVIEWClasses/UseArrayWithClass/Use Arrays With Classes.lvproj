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
		<Item Name="UseArrayOfClasses.vi" Type="VI" URL="../UseArrayOfClasses.vi"/>
		<Item Name="Array - Read Age.vi" Type="VI" URL="../Array - Read Age.vi"/>
		<Item Name="Array - Write Age.vi" Type="VI" URL="../Array - Write Age.vi"/>
		<Item Name="Create Array Of Simple Arithmetic Class Instances.vi" Type="VI" URL="../Create Array Of Simple Arithmetic Class Instances.vi"/>
		<Item Name="Do Operations - Use Dynamic Dispatch Method.vi" Type="VI" URL="../Do Operations - Use Dynamic Dispatch Method.vi"/>
		<Item Name="Do Operations - Use Static Dispatch Method.vi" Type="VI" URL="../Do Operations - Use Static Dispatch Method.vi"/>
		<Item Name="Get Results.vi" Type="VI" URL="../Get Results.vi"/>
		<Item Name="Set Numbers And Operations On Instances.vi" Type="VI" URL="../Set Numbers And Operations On Instances.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="myClass.lvclass" Type="LVClass" URL="../../ClassDefinitions/SimpleClassWithProperties/myClass.lvclass"/>
			<Item Name="SimpleArithmetic.lvclass" Type="LVClass" URL="../../ClassDefinitions/SimpleClassWithMethods/SimpleArithmetic.lvclass"/>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
