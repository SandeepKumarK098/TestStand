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
		<Item Name="UseArrayOfClusterWithClasses.vi" Type="VI" URL="../UseArrayOfClusterWithClasses.vi"/>
		<Item Name="Array Of Clusters - Read Age.vi" Type="VI" URL="../Array Of Clusters - Read Age.vi"/>
		<Item Name="Array Of Clusters - Write Age.vi" Type="VI" URL="../Array Of Clusters - Write Age.vi"/>
		<Item Name="Create Cluster Array Of Simple Arithmetic Class Instances.vi" Type="VI" URL="../Create Cluster Array Of Simple Arithmetic Class Instances.vi"/>
		<Item Name="Do Operations - Use Dynamic Dispatch Method - ArrayOfClusters.vi" Type="VI" URL="../Do Operations - Use Dynamic Dispatch Method - ArrayOfClusters.vi"/>
		<Item Name="Do Operations - Use Static Dispatch Method - ArrayOfClusters.vi" Type="VI" URL="../Do Operations - Use Static Dispatch Method - ArrayOfClusters.vi"/>
		<Item Name="Get Results - ArrayOfClusters.vi" Type="VI" URL="../Get Results - ArrayOfClusters.vi"/>
		<Item Name="Set Values On Instances.vi" Type="VI" URL="../Set Values On Instances.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="myClass.lvclass" Type="LVClass" URL="../../ClassDefinitions/SimpleClassWithProperties/myClass.lvclass"/>
			<Item Name="SimpleArithmetic.lvclass" Type="LVClass" URL="../../ClassDefinitions/SimpleClassWithMethods/SimpleArithmetic.lvclass"/>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
