<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="23002006">
	<Property Name="NI.LV.All.SourceOnly" Type="Bool">true</Property>
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
		<Item Name="Library.lvlib" Type="Library" URL="../VIs in Library in Project Context/Library.lvlib"/>
		<Item Name="VI in Project.vi" Type="VI" URL="../VI in Project.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="Delimited String to 1D String Array.vi" Type="VI" URL="/&lt;vilib&gt;/AdvancedString/Delimited String to 1D String Array.vi"/>
				<Item Name="Join Strings.vi" Type="VI" URL="/&lt;vilib&gt;/AdvancedString/Join Strings.vi"/>
			</Item>
			<Item Name="SubVI1.vi" Type="VI" URL="../../../ErrorCases/Support - SubVIs/SubVI1.vi"/>
			<Item Name="SubVI2.vi" Type="VI" URL="../../../ErrorCases/Support - SubVIs/SubVI2.vi"/>
			<Item Name="SubVI3.vi" Type="VI" URL="../../../ErrorCases/Support - SubVIs/SubVI3.vi"/>
			<Item Name="SubVI-string.vi" Type="VI" URL="../../../ErrorCases/Support - SubVIs/SubVI-string.vi"/>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
