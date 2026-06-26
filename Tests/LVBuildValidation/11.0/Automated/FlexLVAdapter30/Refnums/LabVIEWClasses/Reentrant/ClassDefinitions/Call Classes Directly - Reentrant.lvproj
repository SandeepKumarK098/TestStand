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
		<Item Name="SimpleClassWithProperties" Type="Folder">
			<Item Name="MyClass - Reentrant.lvclass" Type="LVClass" URL="../SimpleClassWithProperties/MyClass - Reentrant.lvclass"/>
			<Item Name="Read Age Wrapper - Reentrant.vi" Type="VI" URL="../SimpleClassWithProperties/Read Age Wrapper - Reentrant.vi"/>
			<Item Name="UseClass - Reentrant.vi" Type="VI" URL="../SimpleClassWithProperties/UseClass - Reentrant.vi"/>
			<Item Name="Write Age Wrapper - Reentrant.vi" Type="VI" URL="../SimpleClassWithProperties/Write Age Wrapper - Reentrant.vi"/>
		</Item>
		<Item Name="SimpleClassWithMethods" Type="Folder">
			<Item Name="Create Class Instance - Reentrant.vi" Type="VI" URL="../SimpleClassWithMethods/Create Class Instance - Reentrant.vi"/>
			<Item Name="DoOperationDynamicDispatchMethod Wrapper - Reentrant.vi" Type="VI" URL="../SimpleClassWithMethods/DoOperationDynamicDispatchMethod Wrapper - Reentrant.vi"/>
			<Item Name="SimpleArithmetic - Reentrant.lvclass" Type="LVClass" URL="../SimpleClassWithMethods/SimpleArithmetic - Reentrant.lvclass"/>
			<Item Name="DoOperationStaticDispatchMethod Wrapper - Reentrant.vi" Type="VI" URL="../SimpleClassWithMethods/DoOperationStaticDispatchMethod Wrapper - Reentrant.vi"/>
			<Item Name="Read Result Wrapper - Reentrant.vi" Type="VI" URL="../SimpleClassWithMethods/Read Result Wrapper - Reentrant.vi"/>
			<Item Name="SetNumbersAndOperationMethod Wrapper - Reentrant.vi" Type="VI" URL="../SimpleClassWithMethods/SetNumbersAndOperationMethod Wrapper - Reentrant.vi"/>
		</Item>
		<Item Name="Dependencies" Type="Dependencies"/>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
