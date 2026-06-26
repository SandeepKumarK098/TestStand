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
		<Item Name="UseClusterWithClass.vi" Type="VI" URL="../UseClusterWithClass.vi"/>
		<Item Name="Cluster - Get Result.vi" Type="VI" URL="../Cluster - Get Result.vi"/>
		<Item Name="Cluster - Read Age.vi" Type="VI" URL="../Cluster - Read Age.vi"/>
		<Item Name="Cluster - Write Age.vi" Type="VI" URL="../Cluster - Write Age.vi"/>
		<Item Name="Create Cluster Of Simple Arithmetic Class Instance.vi" Type="VI" URL="../Create Cluster Of Simple Arithmetic Class Instance.vi"/>
		<Item Name="Do Operation - Use Dynamic Dispatch Method.vi" Type="VI" URL="../Do Operation - Use Dynamic Dispatch Method.vi"/>
		<Item Name="Do Operation - Use Static Dispatch Method.vi" Type="VI" URL="../Do Operation - Use Static Dispatch Method.vi"/>
		<Item Name="Set Number And Operation On Instance.vi" Type="VI" URL="../Set Number And Operation On Instance.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="myClass.lvclass" Type="LVClass" URL="../../ClassDefinitions/SimpleClassWithProperties/myClass.lvclass"/>
			<Item Name="SimpleArithmetic.lvclass" Type="LVClass" URL="../../ClassDefinitions/SimpleClassWithMethods/SimpleArithmetic.lvclass"/>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
